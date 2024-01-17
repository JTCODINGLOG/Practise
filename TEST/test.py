while True:
    try:
        return n = int(input("height>: "))
    except ValueError:
        print("Not an integer")

k = n

for i in range(n):
    k -= 1
    print(" " * k + "#" * (i+1))
