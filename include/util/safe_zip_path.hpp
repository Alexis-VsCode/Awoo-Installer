#pragma once
#include <string_view>

namespace inst::zip {
// Pure C++17 validator; independent from libnx and minizip.
inline bool isSafeRelativePath(std::string_view path) {
    if (path.empty() || path.size() > 1024 || path.front() == '/') return false;
    for (unsigned char ch : path) {
        if (ch < 32 || ch == 127 || ch == '\\' || ch == ':') return false;
    }
    size_t start = 0;
    while (start < path.size()) {
        const size_t end = path.find('/', start);
        const size_t stop = end == std::string_view::npos ? path.size() : end;
        const auto component = path.substr(start, stop - start);
        if (component.empty() || component == "." || component == "..") return false;
        if (end == std::string_view::npos) break;
        start = end + 1;
        if (start == path.size()) return true;
    }
    return true;
}
}
