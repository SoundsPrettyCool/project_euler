// Helpers for reading Project Euler input files.
//
// Header-only: every function is `inline`, so this file can be included from
// any number of .cpp files without "multiple definition" link errors.
//
// Usage:
//     #include "file_utils.hpp"
//
//     auto file = openFile("problems/022_names_scores/names.txt");
//     if (!file) {
//         std::cerr << "could not open file\n";
//         return 1;
//     }
//     std::vector<std::string> names = readQuotedList(*file);

#pragma once

#include <cctype>
#include <expected>
#include <filesystem>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

enum class FileError { FILE_NOT_FOUND };

// Opens `path` for reading. Relative paths are resolved from the current working
// directory, which is the repo root when run via the VS Code tasks.
inline std::expected<std::ifstream, FileError> openFile(const std::filesystem::path& path) {
    std::ifstream file(path);

    if (!file) {
        return std::unexpected(FileError::FILE_NOT_FOUND);
    }
    return file;
}

// Splits the rest of `stream` on `delimiter`, e.g. "a,b,c" -> {"a", "b", "c"}.
// Empty pieces (from ",," or a trailing delimiter) are skipped.
inline std::vector<std::string> splitStream(std::istream& stream, char delimiter) {
    std::vector<std::string> pieces;
    std::string piece;

    while (std::getline(stream, piece, delimiter)) {
        if (!piece.empty()) {
            pieces.push_back(std::move(piece));
        }
    }
    return pieces;
}

// Reads a file shaped like "MARY","PATRICIA",... into {"MARY", "PATRICIA", ...}.
// Quotes and surrounding whitespace (including a trailing newline) are removed.
inline std::vector<std::string> readQuotedList(std::istream& stream, char delimiter = ',') {
    std::vector<std::string> items;

    for (std::string& item : splitStream(stream, delimiter)) {
        std::erase(item, '"');
        std::erase_if(item, [](unsigned char c) { return std::isspace(c); });
        if (!item.empty()) {
            items.push_back(std::move(item));
        }
    }
    return items;
}

// Reads every line of `stream`, with any trailing '\r' (Windows line endings) removed.
inline std::vector<std::string> readLines(std::istream& stream) {
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        lines.push_back(std::move(line));
    }
    return lines;
}
