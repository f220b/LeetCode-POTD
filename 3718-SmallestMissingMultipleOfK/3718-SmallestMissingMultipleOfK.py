# Last updated: 9/5/2026, 12:05:39 AM
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        num = 0
        st = set(nums)
        while True:
            num += k
            if num not in st:
                return num
        
        return -1