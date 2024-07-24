class MyCircularQueue:

    def __init__(self, k: int):
        self.size = k
        self.rear = 0
        self.front = 0
        self.queue = [0] * k
        self.empty = True
        
    def enQueue(self, value: int) -> bool:
        if not self.empty and self.rear == self.front:
            return False
        self.queue[self.rear] = value
        self.rear = (self.rear + 1) % self.size
        self.empty = False
        return True

    def deQueue(self) -> bool:
        if self.isEmpty(): return False
        self.front += 1
        self.front %= self.size
        if self.front == self.rear:
            self.empty = True
        return True

    def Front(self) -> int:
        return self.queue[self.front] if not self.isEmpty() else -1

    def Rear(self) -> int:
        return self.queue[self.rear-1] if not self.isEmpty() else -1

    def isEmpty(self) -> bool:
        return self.empty
        
    def isFull(self) -> bool:
        return not self.empty and self.front == self.rear
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()