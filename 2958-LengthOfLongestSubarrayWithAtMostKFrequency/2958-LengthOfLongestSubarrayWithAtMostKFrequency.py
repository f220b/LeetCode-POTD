# Last updated: 9/5/2026, 12:16:42 AM
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