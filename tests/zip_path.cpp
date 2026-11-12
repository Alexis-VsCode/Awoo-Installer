#include "util/safe_zip_path.hpp"
#include <cassert>
#include <string>
int main() {
    const std::string valid[] = {"a", "a.nro", "romfs/lang/es-419.json", "folder/", "a/b/c.txt", "my folder/file.txt"};
    const std::string invalid[] = {"", "../file", "a/../file", "./file", "a/./file", "//", "/root", "a//file", "C:/file", "sdmc:/file", "a\\file", "a/\\x", "a/..", "a/.", std::string("a\0b",3), std::string("a\x01b",3), std::string(1025,'x')};
    for (const auto& x : valid) assert(inst::zip::isSafeRelativePath(x));
    for (const auto& x : invalid) assert(!inst::zip::isSafeRelativePath(x));
}
