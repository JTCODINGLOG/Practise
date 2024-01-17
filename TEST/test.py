from cs50 import get_int

while True:
    n = get_int("height: ")
    if n > 0:
        break

k = n
for i in range(n):
    k -= 1
    print(" " * k + "#" * (i+1))
