# Last updated: 8/16/2026, 6:46:46 PM
class Solution:
    def longestSubsequence(self, nums: list[int]) -> int:
        tot = nz = 0

        for n in nums:
            nz |= n > 0
            tot ^= n

        return nz * (len(nums) - (not tot))
