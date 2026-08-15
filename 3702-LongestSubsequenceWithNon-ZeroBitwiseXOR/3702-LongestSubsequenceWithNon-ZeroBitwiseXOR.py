# Last updated: 8/15/2026, 11:41:09 PM
1class Solution:
2    def longestSubsequence(self, nums: list[int]) -> int:
3        tot = nz = 0
4
5        for n in nums:
6            nz |= n > 0
7            tot ^= n
8
9        return nz * (len(nums) - (not tot))
10