# Last updated: 9/5/2026, 12:24:02 AM
from typing import List

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        i = nums.index(min(nums))
        j = nums.index(max(nums))
        if i > j:
            i, j = j, i
        # i < j now
        # Option 1: remove both from front -> need to delete up to the later index
        opt1 = j + 1
        # Option 2: remove both from back -> need to delete from the earlier index to end
        opt2 = n - i
        # Option 3: remove one from front, one from back
        opt3 = (i + 1) + (n - j)
        return min(opt1, opt2, opt3)