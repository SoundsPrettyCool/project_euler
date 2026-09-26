// Problem 17: Number Letter Counts
// https://projecteuler.net/problem=17
//
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out
// in words, how many letters would be used? (No spaces or hyphens, and "and"
// is used per British usage, e.g. "three hundred and forty-two".)

#include <array>
#include <iostream>
#include <string>

// Converts 0..99 to words (no spaces/hyphens). 0 becomes the empty string.
std::string numberToWords(int n) {
    static const std::array<std::string, 20> ones = {
        "",        "one",     "two",       "three",    "four",
        "five",    "six",     "seven",     "eight",    "nine",
        "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    static const std::array<std::string, 10> tens = {
        "", "", "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (n < 20) {
        return ones[n];
    }
    return tens[n / 10] + ones[n % 10];
}

// Extends numberToWords to handle 0..1000.
std::string numberToWordsExtended(int n) {
    if (n < 100) {
        return numberToWords(n);
    }
    if (n < 1000) {
        int hundreds = n / 100;
        int remainder = n % 100;
        std::string words = numberToWords(hundreds) + "hundred";
        if (remainder != 0) {
            words += "and" + numberToWords(remainder);
        }
        return words;
    }
    if (n == 1000) {
        return "onethousand";
    }
    return "";
}

int main() {
    std::size_t counter = 0;
    for (int i = 1; i <= 1000; ++i) {
        counter += numberToWordsExtended(i).size();
    }

    std::cout << counter << '\n';
    return 0;
}
