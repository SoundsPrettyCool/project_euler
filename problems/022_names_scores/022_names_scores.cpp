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
#include <file_utils.hpp>
#include <string_utils.hpp>

constexpr std::string_view NAMES_PATH = "/workspaces/project_euler/problems/022_names_scores/names.txt";

int main() {
    std::string names_path_string(NAMES_PATH);
    auto file = openFile(names_path_string);

    if (!file.has_value()) {
        return 1;
    }
    std::vector<std::string> names = readQuotedList(file.value());
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
