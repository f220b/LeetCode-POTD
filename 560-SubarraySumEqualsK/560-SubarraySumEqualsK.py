# Last updated: 4/3/2026, 1:59:37 PM
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sum, cnt = 0, 0
        prefixSum = {0 : 1}
        for x in nums:
            sum += x
            rem = sum - k
            if rem in prefixSum:
                cnt += prefixSum[rem]
            prefixSum[sum] = prefixSum.get(sum, 0) + 1

        return cnt