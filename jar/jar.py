class Jar:
    def __init__(self, capacity = 12):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "'🍪'*{self.size}"

    def deposit(self, n):
        self.size += n

    def withdraw(self, n):
        self.size -= n
        if self.size < 0:
            raise ValueError

    @property
    def capacity(self):
        return self.capacity

    @capacity.setter
    def capacity(self, value):
        if value < 0:
            raise ValueError ("Capacity cannot be negative")

    @property
    def size(self):
        return self.size

    @size.setter
    def size(self, value):
        if 0 < value > self.capacity:
        return ValueError ("The number of cookies is over/under the capacity of the jar")



jar = Jar()
jar.print()

