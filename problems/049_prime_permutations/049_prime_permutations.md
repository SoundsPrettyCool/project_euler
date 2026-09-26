# Problem 49: Prime Permutations

- **Link:** https://projecteuler.net/problem=49
- **Solution:** [049_prime_permutations.cpp](049_prime_permutations.cpp)

## Problem

The sequence 1487, 4817, 8147 goes up by 3330 each step. Every term is prime, and the terms are digit permutations of each other.
Find the other increasing 4-digit sequence with this property and concatenate its three terms.

## Approach

1. Find every 4-digit prime (1000–9999).
2. Group the primes by their **sorted digits**. For example, 1487, 4817 and 8147 all map to `"1478"`. Each group then contains primes that are permutations of one another.
3. Within each group, try each pair `a < b` and check whether `c = 2b - a` is also in the group. If it is, `a, b, c` is an arithmetic sequence.
4. Print each match as a concatenated string. The known example (1487…) is printed too, along with the new one.

## C++ notes

- `isPrime` only checks divisors up to `sqrt(n)` (`i * i <= n`). That is far faster than checking up to `n`.
- `std::sort` on a `std::string` sorts its characters. This makes a quick anagram key that replaces the `defaultdict` counting in the Python version.
- `std::map<std::string, std::vector<int>>`: `operator[]` default-constructs an empty vector for a new key, just like Python's `defaultdict(list)`.
- Primes are added in increasing order, so each group is already sorted. That lets `std::binary_search` look up `c`.
- `for (const auto& [key, primes] : anagramGroups)` uses C++17 structured bindings.

## Differences from the original Python attempt

The Python version never printed anything, and its logic would have missed the answer:
- It only kept anagram lists of length exactly 3. Real groups often have more members. The 1487 group has 8 primes.
- The key prime itself wasn't part of the list it checked.

Grouping by sorted digits and checking every pair fixes both problems.
