
n = int(input("How high?: " ))

for i in range(n):
    for j in range(n-i):
        print(" ", end="")

    for k in range(n):
        print("#", end="")
    print()


