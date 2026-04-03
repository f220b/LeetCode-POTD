# Last updated: 4/3/2026, 2:00:45 PM
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j = 0, 0
        l = len(nums)
        while i < l and j < l:
            while j < l and nums[j] == 0:
                j += 1
            if j < l:
                nums[i] = nums[j]
                i += 1
                j += 1
        while i < l:
            nums[i] = 0
            i += 1