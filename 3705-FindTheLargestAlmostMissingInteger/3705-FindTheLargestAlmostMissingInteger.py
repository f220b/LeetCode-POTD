# Last updated: 8/25/2026, 10:39:54 PM
from collections import Counter
from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq = Counter(nums)

        if k == n:
            return max(nums)

        if k == 1:
            singles = [x for x in nums if freq[x] == 1]
            return max(singles) if singles else -1

        cands = [x for x in (nums[0], nums[-1]) if freq[x] == 1]
        return max(cands) if cands else -1