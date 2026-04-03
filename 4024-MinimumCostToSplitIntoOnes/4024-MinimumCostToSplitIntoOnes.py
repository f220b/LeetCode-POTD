# Last updated: 4/3/2026, 1:49:14 PM
class Solution:
    def minCost(self, n: int) -> int:
        cost = ((n - 1) * n) // 2
        return cost