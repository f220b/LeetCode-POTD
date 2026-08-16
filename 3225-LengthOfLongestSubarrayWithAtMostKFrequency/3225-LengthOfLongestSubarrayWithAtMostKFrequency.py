# Last updated: 8/16/2026, 6:50:32 PM
from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mpp = defaultdict(int)
        left, ans = 0, 0

        for right, x in enumerate(nums):
            mpp[x] += 1

            while mpp[x] > k:
                mpp[nums[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans