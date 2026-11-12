// Safe ZIP extraction for Awoo Installer Community.
// Original ZIP handling in Awoo referenced AtlasNX/Kosmos-Updater FileManager.
#include "util/unzip.hpp"
#include "util/safe_zip_path.hpp"
#include <minizip/unzip.h>
#include <array>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <set>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

namespace {
constexpr size_t kMaxName = 1024;
constexpr size_t kMaxEntries = 4096;
constexpr unsigned long long kMaxFileBytes = 64ULL * 1024 * 1024;
constexpr unsigned long long kMaxArchiveBytes = 256ULL * 1024 * 1024;

bool validInfo(const unz_file_info& info, const std::string& name) {
    if (!inst::zip::isSafeRelativePath(name)) return false;
    const mode_t type = static_cast<mode_t>((info.external_fa >> 16) & S_IFMT);
    if (type != 0 && type != S_IFREG && type != S_IFDIR) return false;
    if (info.uncompressed_size > kMaxFileBytes) return false;
    if (name.back() == '/' && info.uncompressed_size != 0) return false;
    if (type == S_IFDIR && name.back() != '/') return false;
    return true;
}

bool fileInfo(unzFile archive, unz_file_info& info, std::string& name) {
    if (unzGetCurrentFileInfo(archive, &info, nullptr, 0, nullptr, 0, nullptr, 0) != UNZ_OK) return false;
    if (info.size_filename == 0 || info.size_filename > kMaxName) return false;
    std::array<char, kMaxName + 1> chars{};
    if (unzGetCurrentFileInfo(archive, &info, chars.data(), static_cast<uLong>(chars.size()), nullptr, 0, nullptr, 0) != UNZ_OK) return false;
    name.assign(chars.data(), static_cast<size_t>(info.size_filename));
    return validInfo(info, name);
}

bool existingDirectory(const std::string& path) {
    struct stat info{};
    return lstat(path.c_str(), &info) == 0 && S_ISDIR(info.st_mode);
}

bool createParentDirectories(const std::string& path) {
    for (size_t offset = 0; (offset = path.find('/', offset)) != std::string::npos; ++offset) {
        const std::string prefix = path.substr(0, offset);
        if (prefix.empty() || prefix.back() == ':') continue;
        if (mkdir(prefix.c_str(), 0775) != 0 && errno != EEXIST) return false;
        // Existing parent directories must not be symbolic links.
        if (!existingDirectory(prefix)) return false;
    }
    return true;
}

bool extractMember(unzFile archive, const std::string& path, const unz_file_info& info) {
    if (!createParentDirectories(path)) return false;
    if (path.back() == '/') {
        return mkdir(path.c_str(), 0775) == 0 || (errno == EEXIST && existingDirectory(path));
    }
    struct stat existing{};
    if (lstat(path.c_str(), &existing) == 0) return false;
    if (errno != ENOENT) return false;

    const std::string staging = path + ".awoo-extract-part";
    const int fd = open(staging.c_str(), O_WRONLY | O_CREAT | O_EXCL, 0664);
    if (fd < 0) return false;
    FILE* file = fdopen(fd, "wb");
    if (!file) { close(fd); std::remove(staging.c_str()); return false; }

    bool good = unzOpenCurrentFile(archive) == UNZ_OK;
    unsigned long long total = 0;
    std::array<unsigned char, 32768> buffer{};
    while (good) {
        const int received = unzReadCurrentFile(archive, buffer.data(), static_cast<unsigned>(buffer.size()));
        if (received < 0) { good = false; break; }
        if (received == 0) break;
        total += static_cast<unsigned>(received);
        if (total > info.uncompressed_size || total > kMaxFileBytes ||
            fwrite(buffer.data(), 1, static_cast<size_t>(received), file) != static_cast<size_t>(received)) {
            good = false;
            break;
        }
    }
    if (good && total != info.uncompressed_size) good = false;
    if (good && fflush(file) != 0) good = false;
    if (good && fsync(fileno(file)) != 0) good = false;
    if (fclose(file) != 0) good = false;
    if (unzCloseCurrentFile(archive) != UNZ_OK) good = false;

    if (good && rename(staging.c_str(), path.c_str()) == 0) return true;
    std::remove(staging.c_str());
    return false;
}

bool validateArchive(unzFile archive) {
    int status = unzGoToFirstFile(archive);
    if (status != UNZ_OK) return false;
    std::set<std::string> seen;
    size_t entries = 0;
    unsigned long long totalBytes = 0;
    while (status == UNZ_OK) {
        unz_file_info info{};
        std::string name;
        if (++entries > kMaxEntries || !fileInfo(archive, info, name)) return false;
        if (!seen.insert(name).second) return false;
        totalBytes += info.uncompressed_size;
        if (totalBytes > kMaxArchiveBytes) return false;
        status = unzGoToNextFile(archive);
    }
    return status == UNZ_END_OF_LIST_OF_FILE;
}
}

namespace inst::zip {
bool extractFile(const std::string& filename, const std::string& destination) {
    if (filename.empty() || destination.empty() || destination.back() != '/') return false;
    unzFile archive = unzOpen(filename.c_str());
    if (!archive) return false;
    bool success = validateArchive(archive);
    int status = success ? unzGoToFirstFile(archive) : UNZ_END_OF_LIST_OF_FILE;
    while (success && status == UNZ_OK) {
        unz_file_info info{};
        std::string name;
        if (!fileInfo(archive, info, name) || !extractMember(archive, destination + name, info)) {
            success = false;
            break;
        }
        status = unzGoToNextFile(archive);
    }
    if (success && status != UNZ_END_OF_LIST_OF_FILE) success = false;
    if (unzClose(archive) != UNZ_OK) success = false;
    return success;
}
}
