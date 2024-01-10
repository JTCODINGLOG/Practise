n = int(input("height>: "))
k = n


for i in range(n):
    k -= 1
    print(" " * k + "#" * (i+1))
