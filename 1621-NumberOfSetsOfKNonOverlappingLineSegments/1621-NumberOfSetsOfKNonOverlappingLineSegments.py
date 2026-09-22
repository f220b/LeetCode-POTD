# Last updated: 9/22/2026, 11:26:50 PM
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        prev = [[0] * 2 for _ in range(k + 1)]
        prev[k][0] = prev[k][1] = 1

        curr = [[0] * 2 for _ in range(k + 1)]

        for i in range(n - 1, -1, -1):
            curr[k][0] = curr[k][1] = 1
            for cnt in range(k - 1, -1, -1):
                curr[cnt][1] = (curr[cnt + 1][0] + prev[cnt][1]) % MOD
                curr[cnt][0] = (prev[cnt][1] + prev[cnt][0]) % MOD
            prev, curr = curr, prev

        return prev[0][0]
