# Last updated: 4/3/2026, 2:04:50 PM
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        currSum = 0
        mpp = {}

        for i in range(0, len(nums)):
            diff = target - nums[i]
            if diff in mpp:
                return [mpp[diff], i]
            mpp[nums[i]] = i
        return []