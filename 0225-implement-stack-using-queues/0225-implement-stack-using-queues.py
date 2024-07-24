class MyStack:

    def __init__(self):
        self.stack = []
        self.last = -1

    def push(self, x: int) -> None:
        self.last += 1
        if len(self.stack) > self.last:
            self.stack[self.last] = x
        else: self.stack.append(x)

    def pop(self) -> int:
        self.last -= 1
        return self.stack[self.last + 1]

    def top(self) -> int:
        return self.stack[self.last]

    def empty(self) -> bool:
        return self.last < 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()