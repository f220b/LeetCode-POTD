# Last updated: 4/3/2026, 2:03:47 PM
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum, maxSum = 0, float('-inf')
        for num in nums:
            currSum += num
            maxSum = max(maxSum, currSum)
            if currSum < 0:
                currSum = 0
        return maxSum