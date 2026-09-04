# Last updated: 9/5/2026, 12:25:07 AM
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right = 0, 0
        minDiff = float('inf')

        while right < len(nums):
            if right - left + 1 > k:
                left += 1
            if right - left + 1 == k:
                diff = nums[right] - nums[left]
                minDiff = min(minDiff, diff)
            right += 1
        
        return minDiff