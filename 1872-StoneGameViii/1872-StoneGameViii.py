# Last updated: 9/5/2026, 12:26:24 AM
class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        prefixSum = [0] * n

        for i, x in enumerate(stones):
            if i == 0:
                prefixSum[0] = x
                continue
            prefixSum[i] = prefixSum[i - 1] + x

        dp = [0] * n
        dp[n - 1] = prefixSum[n - 1]
        for i in range(n - 2, -1, -1):
            take = prefixSum[i] - dp[i + 1]
            skip = dp[i + 1]
            dp[i] = max(take, skip)

        return dp[1]
