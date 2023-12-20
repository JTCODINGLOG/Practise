class Jar:
    def __init__(self, capacity = 12):
        if self.capacity < 0:
            raise ValueError
        self.capacity = capacity



    def __str__(self):
        return f"{'🍪'*self.size}"

    def deposit(self, n):
        self.size += n
        if self.size > self.capacity:
            raise ValueError

    def withdraw(self, n):
        self.size -= n
        if self.size < 0:
            raise ValueError

    @property
    def capacity(self):
        return self.capacity

    @capacity.setter
    def capacity(self, value)
        if value < 0:
            raise ValueError

    @property
    def size(self):
        return self.size


jar = Jar()
jar.print()

