
n = int(input("How high?: " ))

for i in range(n):
    j = i
    for j in range(n):
        print(" ", end="")
    k = n-i
    for k in range(n):
        print("#", end="")
    print()


