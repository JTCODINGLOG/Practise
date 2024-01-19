from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break
coins = 0
def changewith(coin, coins, change):
    if change < coin:
        return coins, change
    coins = coins + int(change/coin)
    change = round(change % coin, 2)
    return coins, change

coins, change = changewith(0.25, coins, change)
coins, change = changewith(0.10, coins, change)
coins, change = changewith(0.05, coins, change)
coins, change = changewith(0.01, coins, change)
print(coins)


