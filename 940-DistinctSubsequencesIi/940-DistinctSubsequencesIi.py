# Last updated: 9/22/2026, 11:29:50 PM
class Solution:
    def distinctSubseqII(self, s):
        n = len(s)
        MOD = 10**9 + 7

        dp = [1] * n
        result = 0

        for i in range(n):

            for j in range(i):
                if s[i] != s[j]:
                    dp[i] = (dp[i] + dp[j]) % MOD

            result = (result + dp[i]) % MOD

        return result