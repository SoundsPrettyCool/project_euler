# CLAUDE.md

This repo is where I work through [Project Euler](https://projecteuler.net) problems **in C++ to learn the language**.
The goal is learning, not collecting answers.

## How to help me

- **Never give me the numeric answer to a Project Euler problem**, whether I've solved it or not.
  - Don't run code to reveal a result I haven't produced myself.
  - Don't recall answers from memory.
- **Never write a full solution** to a problem I'm working on unless I explicitly ask for one with words like "show me the full solution".
- Act like a tutor:
  - Ask guiding questions.
  - Point me to the relevant math idea or C++ feature.
  - Give progressively stronger hints. Start small and only go further if I ask.
- When I share code:
  - Point out bugs, performance problems and non-idiomatic C++, and explain *why*.
  - Let me write the fix myself. A short snippet showing a language feature (e.g. how `std::map` or structured bindings work) is fine. Applying it to my problem is my job.
- If I ask "is my answer right?", tell me whether my *approach* is correct or where it breaks. Don't state the correct number.
- Explain C++ concepts in depth when they come up: memory, references vs. copies, STL containers, undefined behavior, modern C++ idioms.

## Repo layout

Each problem has its own folder, `problems/NNN_problem_name/` (NNN zero-padded to 3 digits), containing:

- `NNN_problem_name.cpp`: the solution.
- `NNN_problem_name.md`: my notes (approach, C++ concepts learned, gotchas).
  - Notes describe the approach and what I learned. They do **not** include the final answer.

The top-level `build/` folder (git-ignored) holds the CMake build tree. Binaries are in `build/bin/`.

## Building and running

- Standard: C++20, compiled with `g++` via CMake.
- `CMakeLists.txt` globs `problems/*/*.cpp` and creates one executable target per file, named after the file (e.g. `031_coin_sums`). New problems are picked up automatically.
- Binaries go in `build/bin/`. Programs are run from the repo root.
- In VS Code, open a problem's `.cpp` file, then:
  - **Build and run:** `Terminal → Run Task → CMake: build and run active file` (default test task).
  - **Build only:** `Ctrl+Shift+B`.
  - **Build every problem:** `Terminal → Run Task → CMake: build all problems`.
  - **Debug:** `F5` ("CMake: debug active file").
- From the terminal:

  ```sh
  cmake -S . -B build && cmake --build build --target 031_coin_sums && ./build/bin/031_coin_sums
  ```

## Conventions

- Put a header comment in each `.cpp` with the problem number, name, link and statement.
- Use `camelCase` for functions and variables.
- Code should compile cleanly with `-Wall -Wextra -Wpedantic`.
