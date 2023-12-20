class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0


    def __str__(self):
        return f"{'🍪'*self.size}"

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
