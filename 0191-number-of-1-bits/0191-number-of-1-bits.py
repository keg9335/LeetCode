class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        for i in range(32):
            comp = 1 << i
            if (n & comp) == comp:
                cnt += 1
                
        return cnt