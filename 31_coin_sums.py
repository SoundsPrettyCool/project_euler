# 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

def coin_sums(target, coins, start_idx, memo= {}):
    if (target,start_idx) in memo:
        return memo[(target, start_idx)]
    if target == 0:
        return 1
    elif target < 0:
        return 0

    sum = 0

    for i in range(start_idx, len(coins)):
        sum += coin_sums(target-coins[i], coins, i, memo)

    if (target,start_idx) not in memo:
        memo[(target,start_idx)] = sum

    return sum

coins = [1,2,5,10,20,50,100,200]
print(coin_sums(200, coins, 0))