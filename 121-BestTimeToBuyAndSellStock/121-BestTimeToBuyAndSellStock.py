# Last updated: 4/3/2026, 2:02:34 PM
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best, maxProfit = prices[0], 0

        for i in range(1, len(prices)):
            profit = prices[i] - best
            maxProfit = max(maxProfit, profit)
            best = min(best, prices[i])
        return maxProfit