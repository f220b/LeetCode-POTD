# Last updated: 4/3/2026, 2:01:45 PM
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count, num = 0, nums[0]
        for i in nums:
            if count == 0:
                num = i
            if i == num:
                count += 1
            else:
                count -= 1
        return num