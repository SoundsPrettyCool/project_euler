// Problem 31: Coin Sums
// https://projecteuler.net/problem=31
//
// In the UK the currency is made up of pound (£) and pence (p). There are eight
// coins in general circulation: 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and
// £2 (200p). How many different ways can £2 be made using any number of coins?

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using Memo = std::map<std::pair<int, std::size_t>, long long>;

// Counts the ways to make `target` using coins[startIdx..]. Only allowing coins
// at or after startIdx means each combination is counted once, regardless of order.
long long coinSums(int target, const std::vector<int>& coins, std::size_t startIdx, Memo& memo) {
    if (target == 0) {
        return 1;
    }
    if (target < 0) {
        return 0;
    }

    auto key = std::make_pair(target, startIdx);
    if (auto it = memo.find(key); it != memo.end()) {
        return it->second;
    }

    long long sum = 0;
    for (std::size_t i = startIdx; i < coins.size(); ++i) {
        sum += coinSums(target - coins[i], coins, i, memo);
    }

    memo[key] = sum;
    return sum;
}

int main() {
    const std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    Memo memo;

    std::cout << coinSums(200, coins, 0, memo) << '\n';
    return 0;
}
