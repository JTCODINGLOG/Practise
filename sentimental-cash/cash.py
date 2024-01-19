from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

def changewith(coin, coins, change):
    if change < coin:
        return
    coins = coins + int(change/coin)
    change = change % coin
    if change == 0:
        print(coins)
    return coins, change

changewith(0.25)
changewith(0.0)
changewith(0.05)
changewith(0.01)


#if change % quarters == 0:
#    print(f"Change: {change / quarters}")
#elif change % quarters / dimes



#0.25 0.10 0.05 0.01
