// Problem 22: Names Scores
// https://projecteuler.net/problem=22
//
// Using names.txt, a 46K text file containing over five-thousand first names,
// begin by sorting it into alphabetical order. Then working out the
// alphabetical value for each name, multiply this value by its alphabetical
// position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which is
// worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
// would obtain a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?

#include <iostream>
#include <fstream>
#include <expected>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

constexpr std::string_view NAMES_PATH = "/workspaces/project_euler/problems/022_names_scores/names.txt";
enum class FileFindErrors {FILE_NOT_FOUND};
const std::unordered_map<char, long> ALPHABET{
    {'A', 1},  {'B', 2},  {'C', 3},  {'D', 4},  {'E', 5},  {'F', 6},  {'G', 7},
    {'H', 8},  {'I', 9},  {'J', 10}, {'K', 11}, {'L', 12}, {'M', 13}, {'N', 14},
    {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19}, {'T', 20}, {'U', 21},
    {'V', 22}, {'W', 23}, {'X', 24}, {'Y', 25}, {'Z', 26},
};

std::expected<std::ifstream, FileFindErrors> fetch_file(std::string file_path) {
    std::ifstream file(file_path);

    if (!file) {
        std::cerr << "Could not open names.txt";
        return std::unexpected(FileFindErrors::FILE_NOT_FOUND);
    }
    return file;
}

// Reads a file shaped like "MARY","PATRICIA",... into {"MARY", "PATRICIA", ...}.
std::vector<std::string> readNames(std::ifstream& file) {
    std::vector<std::string> names;
    std::string name;

    // getline with ',' as the delimiter reads one quoted name at a time.
    while (std::getline(file, name, ',')) {
        std::erase(name, '"');  // C++20: remove every '"' from the string
        if (!name.empty()) {
            names.push_back(std::move(name));
        }
    }
    return names;
}

int main() {
    std::string names_path_string(NAMES_PATH);
    auto file = fetch_file(names_path_string);

    if (!file.has_value()) {
        return 1;
    }
    std::vector<std::string> names = readNames(file.value());
    std::ranges::sort(names);
    long total_sum = 0;
    //[name1,name2,name3...]
    for (auto [i, name] : std::views::enumerate(names)) {
        double name_letter_sum = 0;
        //[C, A, R, L...]
        for (auto [j, letter] : std::views::enumerate(name)) {
            name_letter_sum += ALPHABET.at(letter);
        }

        total_sum += (i+1)*name_letter_sum;
    }

    std::cout << "The total score is " << total_sum << "\n";
    return 0;
}
