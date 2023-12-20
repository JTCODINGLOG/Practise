class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        return capacity


    def __str__(self):
        return "n"

    def deposit(self, n):
        if n > capacity:
            raise ValueError
        n = jar._str_(self) + n

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
