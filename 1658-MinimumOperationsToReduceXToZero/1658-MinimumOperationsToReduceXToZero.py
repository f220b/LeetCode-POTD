# Last updated: 10/7/2026, 2:19:38 PM
class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0:
            return -1
        if target == 0:
            return len(nums)

        left = cur = 0
        best = -1
        for right, v in enumerate(nums):
            cur += v
            while cur > target:
                cur -= nums[left]
                left += 1
            if cur == target:
                best = max(best, right - left + 1)

        return -1 if best == -1 else len(nums) - best