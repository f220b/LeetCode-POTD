# Last updated: 8/25/2026, 10:38:07 PM
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        num = 0
        st = set(nums)
        while True:
            num += k
            if num not in st:
                return num
        
        return -1