class Solution:
    def climbStairs(self, n: int) -> int:
        climb = {0:1, 1:1}
        for i in range(2, n+1):
            climb[i] = climb[i-2] + climb[i-1]
        return climb[n]



        