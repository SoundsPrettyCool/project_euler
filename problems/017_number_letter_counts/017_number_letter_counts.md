# Problem 17: Number Letter Counts

- **Link:** https://projecteuler.net/problem=17
- **Solution:** [017_number_letter_counts.cpp](017_number_letter_counts.cpp)

## Problem

Write every number from 1 to 1000 in words, following British usage ("three hundred and forty-two").
Count the letters, leaving out spaces and hyphens.

## Approach

- Build each number's words without spaces, then add up the string lengths.
- `numberToWords` covers 0–99:
  - Below 20, it looks the word up in a table (`ones`), because those words are irregular.
  - From 20 to 99, it joins `tens[n / 10]` and `ones[n % 10]`. `ones[0]` is `""`, so round tens such as `"forty"` work without a special case.
- `numberToWordsExtended` covers 100–1000:
  - The hundreds digit gives `"<digit>hundred"`.
  - If there is a remainder, it adds `"and"` plus the words for the remainder.
  - 1000 is a special case: `"onethousand"`.

## C++ notes

- `std::array<std::string, N>` gives a fixed-size lookup table. Declaring it `static const` builds the table once, not on every call.
- `std::string::size()` returns a `std::size_t`, so the counter uses that type too. This avoids signed/unsigned warnings.
- Python's `a + ('' if cond else b)` became a plain `if` that appends with `+=`, which reads better in C++.

## Gotchas

- The word is "forty", not "fourty".
- Don't forget the British "and", as in "one hundred and fifteen". It adds a lot of letters.
