# Last updated: 4/3/2026, 1:48:28 PM
class Solution:
    def scoreDifference(self, nums: List[int]) -> int:
        cnt1 = cnt2 = 0
        first = True

        for i in range(0, len(nums)):
            # Check for odd
            if nums[i] & 1 == 1:
                first = not first
            if (i + 1) % 6 == 0:
                first = not first
            if first:
                cnt1 += nums[i]
            else:
                cnt2 += nums[i]
        return cnt1 - cnt2
