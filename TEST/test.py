def hast():
    for i in range(quest()):
        j = i
        for j in range(quest()):
            print(" ", end="")
        k = quest()-i
        for k in range(quest()):
            print("#", end="")
    print()




def quest():
    return int(input("How high?: " ))


hast()


