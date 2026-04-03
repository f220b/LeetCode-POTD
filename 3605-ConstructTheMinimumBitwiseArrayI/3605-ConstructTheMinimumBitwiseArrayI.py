# Last updated: 4/3/2026, 1:50:59 PM
class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1]*n

        for i in range(0, n):
            if nums[i] % 2 == 0:
                continue
            target = nums[i]

            for bit in range(32):
                if not (target & (1 << bit)):
                    res = target ^ (1 << (bit - 1))
                    ans[i] = res
                    break
        return ans