# Last updated: 9/5/2026, 12:02:01 AM
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        minIdx = [10**9] * n
        minIdx[n - 1] = nums[n - 1]

        for i in range(n - 2, -1, -1):
            minIdx[i] = min(minIdx[i + 1], nums[i])

        currMax = 0
        for i, x in enumerate(nums):
            currMax = max(currMax, x)
            diff = currMax - minIdx[i]
            if diff <= k:
                return i
        
        return -1