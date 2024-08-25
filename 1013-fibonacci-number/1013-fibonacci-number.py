class Solution:
    def fib(self, n: int) -> int:
        # if n in (0, 1):
        #     return n
        # return self.fib(n-2) + self.fib(n-1)
        fib_dic = {0:0, 1:1}
        for i in range(2, n+1):
            fib_dic[i] = fib_dic[i-1] + fib_dic[i-2]
        return fib_dic[n]