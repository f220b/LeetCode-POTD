# Last updated: 9/5/2026, 12:30:16 AM
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False] * (n + 1)

        for left in range(1, n + 1):
            i = 1
            while i * i <= left:
                if not dp[left - (i**2)]:
                    dp[left] = True

                i += 1

        return dp[n]
