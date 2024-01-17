from cs50 import get_int
from sys import exit

while True:
    n = get_int("Height: ")
    if n > 1 and n < 9:
        break


k = n
for i in range(n):
    k -= 1
    print(" " * k + "#" * (i + 1))

