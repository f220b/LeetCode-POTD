# Last updated: 8/16/2026, 6:57:34 PM
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = [[[-1] * 101 for _ in range(101)] for _ in range(2)]

        def solve(per, i, m):
            if i >= n:
                return 0
            if dp[per][i][m] != -1:
                return dp[per][i][m]
                
            stones = 0
            result = float("-inf") if per == 1 else float("inf")
            for x in range(1, min(2 * m, n - i) + 1):
                stones += piles[i + x - 1]

                if per:
                    result = max(result, stones + solve(0, i + x, max(m, x)))
                else:
                    result = min(result, solve(1, i + x, max(m, x)))
            dp[per][i][m] = result
            return dp[per][i][m]

        return solve(1, 0, 1)
