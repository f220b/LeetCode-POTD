# Last updated: 4/3/2026, 2:00:51 PM
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        actualSum = sum(nums)
        n = len(nums)
        totalSum = (n*(n+1)) // 2
        return totalSum - actualSum