# Last updated: 9/5/2026, 12:31:06 AM
class Solution:
    def stoneGameIII(self, st: List[int]) -> str:
        n = len(st)
        dp = [[0] * (n + 1) for _ in range(2)]

        for i in range(n - 1, -1, -1):
            for per in range(2):
                stones = 0
                dp[1][i] = float('-inf')
                dp[0][i] = float('inf')

                for x in range(1, min(n - i + 1, 4)):
                    stones += st[i + x - 1]
                    dp[1][i] = max(dp[1][i], stones + dp[0][i + x])
                    dp[0][i] = min(dp[0][i], -stones + dp[1][i + x])

        ans = dp[1][0]
        return "Tie" if ans == 0 else ("Alice" if ans > 0 else "Bob")
