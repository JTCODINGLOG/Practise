from cs50 import get_float

quarters = 0.25
dimes = 0.10
nickels = 0.05
pennies = 0.01

while True:
    change = get_float("Change: ")
    if change > 0:
        break
coins = int(change/quarters)
print(coins)


#if change % quarters == 0:
#    print(f"Change: {change / quarters}")
#elif change % quarters / dimes



#0.25 0.10 0.05 0.01
