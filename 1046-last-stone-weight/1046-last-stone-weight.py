class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones.sort()
            a, b = stones.pop(), stones.pop()
            new = abs(a - b)
            stones.append(new)
        
        return stones[0]