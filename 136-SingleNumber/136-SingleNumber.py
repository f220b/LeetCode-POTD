# Last updated: 4/3/2026, 2:02:10 PM
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in nums:
            result = result ^ i
        
        return result