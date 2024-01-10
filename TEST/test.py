def quest():
    n = int(input("How high?: " ))
    return n

def hast(n):
    for i in range(n):
        j = i
        for j in range(quest()):
            print(" ", end="")
        k = quest()-i
        for k in range(quest()):
            print("#", end="")
    print()

def main():
    hast(quest())

main()


