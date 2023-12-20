class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0


    def __str__(self):
        self.n = f"{'🍪'*self.size}"

    def deposit(self, n):
        self.size =+ n
        if self.size > self.capacity:
            raise ValueError

    def withdraw(self, n):
        self.size =- n

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
