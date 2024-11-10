from collections import defaultdict

def is_prime(n):
    i = 2

    while i < n:
        if n % i == 0:
            return False
        i += 1
    return True

def are_anagrams(n1,n2):
    n1_str = str(n1)
    n2_str = str(n2)

    n1_dict = defaultdict(int)

    for num in n1_str:
        n1_dict[num] += 1
    
    for num in n2_str:
        if num not in n1_dict:
            return False
        
        n1_dict[num] -= 1
    
    for num, amount in n1_dict.items():
        if amount != 0:
            return False
    
    return True
        
def prime_permutations():
    prime_nums = []
    anagram_pairs = defaultdict(list)
    sequence_pairs = []
    current = 1000

    while current < 10000:
        if is_prime(current):
            prime_nums.append(current)
        current += 1
    
    for i in range(len(prime_nums)):
        for j in range(i + 1, len(prime_nums)):
            if are_anagrams(prime_nums[i], prime_nums[j]):
                anagram_pairs[prime_nums[i]].append(prime_nums[j])

    for num, pairs in anagram_pairs.items():
        if len(pairs) == 3:
            sequence_pairs.append(pairs)
    
    final_pairs = []
    for pairs in sequence_pairs:
        difference1 = pairs[2] - pairs[1]
        difference2 = pairs[1] - pairs[0]

        if difference1 == difference2:
            final_pairs.append(pairs)

prime_permutations()