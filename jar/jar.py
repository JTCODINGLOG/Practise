class Jar:
    def __init__(self, capacity = 12):
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return print (f{"🍪"*self._size})

    def deposit(self, n):
        self._size += n

    def withdraw(self, n):
        self._size -= n
        if self._size < 0:
            raise ValueError

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, value):
        if value < 0:
            raise ValueError ("Capacity cannot be negative")

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, value):
        if value > self._capacity or value < 0:
            raise ValueError ("The number of cookies is over/under the capacity of the jar")



jar = Jar()
print(jar)

