class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        price_min = sys.maxsize

        for i in range(len(prices)):
            price_min = min(price_min, prices[i])
            profit = max(profit, prices[i] - price_min)
        
        return profit