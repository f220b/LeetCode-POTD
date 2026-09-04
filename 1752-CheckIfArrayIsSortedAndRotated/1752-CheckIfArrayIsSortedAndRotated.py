# Last updated: 9/5/2026, 12:27:50 AM
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