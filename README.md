# project_euler

My [Project Euler](https://projecteuler.net) solutions, written in C++ as a way to learn the language.

Each problem has its own folder in `problems/` with a `.cpp` solution and a matching `.md` notes file:

| #  | Problem | Solution | Notes |
|----|---------|----------|-------|
| 17 | Number Letter Counts | [cpp](problems/017_number_letter_counts/017_number_letter_counts.cpp) | [notes](problems/017_number_letter_counts/017_number_letter_counts.md) |
| 31 | Coin Sums | [cpp](problems/031_coin_sums/031_coin_sums.cpp) | [notes](problems/031_coin_sums/031_coin_sums.md) |
| 49 | Prime Permutations | [cpp](problems/049_prime_permutations/049_prime_permutations.cpp) | [notes](problems/049_prime_permutations/049_prime_permutations.md) |

## Running

Builds use CMake. Every `problems/*/*.cpp` becomes its own executable in `build/bin/`.

Open a `.cpp` file in VS Code, then:

- Run **CMake: build and run active file** from `Terminal → Run Task`.
- Press `Ctrl+Shift+B` to build only.
- Press `F5` to debug.

From the terminal:

```sh
cmake -S . -B build && cmake --build build --target 031_coin_sums && ./build/bin/031_coin_sums
```
