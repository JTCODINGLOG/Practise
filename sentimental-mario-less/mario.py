from cs50 import get_int
from sys import exit

while True:
    n = get_int("Height: ")
    if n > 1 or n < 9:
        exit(0)


k = n
for i in range(n):
    k -= 1
    print(" " * k + "#" * (i + 1))

