class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        mul = x ^ y
        result = 0
        while mul:
            result += mul % 2
            mul //= 2
        return result
