# Creating the dictionary without using external libraries

# Function to convert number to words
def number_to_words(n):
    ones = [
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
        "seventeen", "eighteen", "nineteen"
    ]
    tens = [
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    ]

    if 0 <= n < 20:
        return ones[n]
    elif 20 <= n < 100:
        return tens[n // 10] + ('' if n % 10 == 0 else ones[n % 10])
    elif n == 100:
        return "onehundred"
    else:
        return ""

# Creating the dictionary
# Extending the function to handle numbers up to 1000
def number_to_words_extended(n):
    if n < 100:
        return number_to_words(n)
    elif 100 <= n < 1000:
        hundreds = n // 100
        remainder = n % 100
        return number_to_words(hundreds) + "hundred" + ('' if remainder == 0 else 'and' + number_to_words(remainder))
    elif n == 1000:
        return "onethousand"
    else:
        return ""

# Creating the dictionary for numbers up to 1000
number_to_words_dict_extended = {i: number_to_words_extended(i) for i in range(1001)}
counter = 0
for i, val in number_to_words_dict_extended.items():
    counter += len(val)

print(counter)
