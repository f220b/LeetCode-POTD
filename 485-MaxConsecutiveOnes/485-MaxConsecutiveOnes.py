# Last updated: 4/3/2026, 1:59:56 PM
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curr, best = 0, 0
        for i in nums:
            if i == 1:
                curr += 1
            else:
                curr = 0
            best = max(best, curr)
        return best