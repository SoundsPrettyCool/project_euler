// Problem 49: Prime Permutations
// https://projecteuler.net/problem=49
//
// The arithmetic sequence 1487, 4817, 8147, in which each of the terms increases
// by 3330, is unusual in two ways: (i) each of the three terms is prime, and
// (ii) each of the 4-digit numbers are permutations of one another.
// There is one other 4-digit increasing sequence with this property.
// What 12-digit number do you form by concatenating the three terms?

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Two numbers are digit permutations of each other if their sorted digits match.
std::string sortedDigits(int n) {
    std::string digits = std::to_string(n);
    std::sort(digits.begin(), digits.end());
    return digits;
}

std::vector<std::string> primePermutations() {
    // Group every 4-digit prime by its sorted digits, so each group holds
    // primes that are permutations of one another (in increasing order).
    std::map<std::string, std::vector<int>> anagramGroups;
    for (int n = 1000; n < 10000; ++n) {
        if (isPrime(n)) {
            anagramGroups[sortedDigits(n)].push_back(n);
        }
    }

    // Within each group, pick two terms a < b and check whether the third term
    // c = b + (b - a) is also in the group.
    std::vector<std::string> results;
    for (const auto& [key, primes] : anagramGroups) {
        for (std::size_t i = 0; i < primes.size(); ++i) {
            for (std::size_t j = i + 1; j < primes.size(); ++j) {
                int a = primes[i];
                int b = primes[j];
                int c = b + (b - a);
                if (std::binary_search(primes.begin(), primes.end(), c)) {
                    results.push_back(std::to_string(a) + std::to_string(b) + std::to_string(c));
                }
            }
        }
    }
    return results;
}

int main() {
    for (const std::string& sequence : primePermutations()) {
        std::cout << sequence << '\n';
    }
    return 0;
}
