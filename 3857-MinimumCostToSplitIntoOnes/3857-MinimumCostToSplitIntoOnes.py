# Last updated: 9/5/2026, 12:06:29 AM
class Solution:
    def minCost(self, n: int) -> int:
        cost = ((n - 1) * n) // 2
        return cost