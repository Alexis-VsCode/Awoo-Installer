#include "util/unzip.hpp"
#include <iostream>
int main(int argc, char** argv) {
    if (argc != 3) return 2;
    const bool ok = inst::zip::extractFile(argv[1], argv[2]);
    std::cout << (ok ? "OK" : "REJECTED") << '\n';
    return ok ? 0 : 1;
}
