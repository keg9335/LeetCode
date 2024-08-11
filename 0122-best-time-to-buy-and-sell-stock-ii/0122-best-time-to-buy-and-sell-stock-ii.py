class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        stack = [prices[0]] 
        profit = 0
        for p in prices[1:]:
            p_c = p
            while stack:
                if stack[-1] < p_c:
                    profit += p_c - stack[-1]
                    p_c = stack.pop()
                else:
                    stack.pop()
                    break
            stack.append(p)
        return profit
