class DynamicArray:
    def __init__(self, capacity: int):
        self.size = 0
        self.capacity = capacity
        self.arr = [0] * self.capacity

    def get(self, i: int) -> int:
        # assuming i is valid
        return self.arr[i]

    def set(self, i: int, n: int) -> None:
        # assuming i is valid
        self.arr[i] = n

    def pushback(self, n: int) -> None:
        if self.size == self.capacity:
            self.resize()

        self.size += 1
        self.arr[self.size - 1] = n

    def popback(self) -> int:
        # we don't need to delete it
        self.size -= 1
        return self.arr[self.size]

    def resize(self) -> None:
        self.capacity = self.capacity * 2
        newArr = [0] * self.capacity
        for i in range(len(self.arr)):
            newArr[i] = self.arr[i]
        self.arr = newArr

    def getSize(self) -> int:
        return self.size

    def getCapacity(self) -> int:
        return self.capacity
