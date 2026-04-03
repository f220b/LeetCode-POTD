# Last updated: 4/3/2026, 1:55:39 PM
class Solution:
    def check(self, nums: List[int]) -> bool:
        drops = 0
        l = len(nums)
        for i in range(0, l):
            if nums[i] > nums[(i+1)%l]:
                drops+=1
            if drops > 1:
                return False
        return True