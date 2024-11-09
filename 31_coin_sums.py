# 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

def coin_sums(target, memo={}):
    if target in memo:
        return memo[target]
    if target == 0:
        return 1
    elif target < 0:
        return 0

    sum = 0
    coins = [1,2,5,10,20,50,100,200]

    for coin in coins:
        sum += coin_sums(target-coin, memo)

    if target not in memo:
        memo[target] = sum

    return sum

print(coin_sums(2))