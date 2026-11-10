#pragma once
#include <string>
namespace inst::zip {
    // Destination must end in '/'. Existing files are not overwritten.
    // Extraction does not provide a transaction-wide rollback.
    bool extractFile(const std::string& filename, const std::string& destination);
}
