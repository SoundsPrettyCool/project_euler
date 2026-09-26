# Problem 31: Coin Sums

- **Link:** https://projecteuler.net/problem=31
- **Solution:** [031_coin_sums.cpp](031_coin_sums.cpp)

## Problem

UK coins come in 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
How many different ways can you make £2 from any number of these coins?

## Approach

- Use recursion with memoization: `coinSums(target, coins, startIdx)`.
  - `target == 0`: return 1, because we found one valid combination.
  - `target < 0`: return 0, because we overshot.
  - Otherwise, try every coin from `startIdx` onward and recurse with `target - coin`. Pass the same index `i` so that coin can be used again.
- Only allowing coins at or after `startIdx` puts the coins in non-decreasing order. That way `1+2` and `2+1` count as the same combination.
- The memo key is `(target, startIdx)`, since the answer depends on both.

## C++ notes

- The memo is a `std::map<std::pair<int, std::size_t>, long long>`:
  - `std::pair` already has `operator<`, so it works as a `std::map` key without extra code.
  - `std::unordered_map` would need a custom hash for `pair`.
- The memo is passed by reference (`Memo&`) so every recursive call shares it.
- `if (auto it = memo.find(key); it != memo.end())` uses the C++17 "if with initializer" form. It keeps `it` scoped to the `if`.
- The Python version used a mutable default argument (`memo={}`), a well-known Python pitfall. The dict is shared between calls, which happened to work here. C++ makes the shared state explicit.

## Alternatives

- Bottom-up DP: `ways[0] = 1`. For each coin `c`, for `t` from `c` to 200: `ways[t] += ways[t - c]`. This takes O(coins × target) time and needs no recursion.
