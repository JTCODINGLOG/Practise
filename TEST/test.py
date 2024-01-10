def quest():
    return int(input("How high?: " ))

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


