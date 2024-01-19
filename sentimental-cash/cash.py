from cs50 import get_float

quarters = 0.25
dimes = 0.10
nickels = 0.05
pennies = 0.01

while True:
    change = get_float("Change: ")
    if change > 0:
        break

def changewith(coin):
    if change < coin:
        return
    coins = coins + int(change/coin)
    change = change % coin
    if change == 0:
        print(coins)
    return coins, change

changewith(quarters)
changewith(dimes)
changewith(nickels)
changewith(pennies)


#if change % quarters == 0:
#    print(f"Change: {change / quarters}")
#elif change % quarters / dimes



#0.25 0.10 0.05 0.01
