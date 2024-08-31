class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xFFFFFFFF
        MAX_INT = 0x7FFFFFFF
        v = a ^ b
        c = a & b
        while c:
            v, c = (v ^ (c<<1)) & MASK , v & (c<<1) & MASK

        return v if v <= MAX_INT else ~(v ^ MASK)