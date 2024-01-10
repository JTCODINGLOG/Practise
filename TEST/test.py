def hast():
    n = " " * quest()
    for _ in range(quest()):
        n = n - " " + "#"
        print (n)



def quest():
    return int(input("How high?: " ))


hast()


