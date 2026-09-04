// Last updated: 9/5/2026, 12:05:36 AM
class Solution {
public:
    const int MOD = 1e9 + 7;

    int interleaveCharacters(string word1, string word2, string target) {
        int n1 = word1.length(), n2 = word2.length(), n = target.length();
        int dp[105][105][105];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j)
                dp[i][j][n] = 1;
        }

        for (int k = n - 1; k >= 0; --k) {
            for (int i = n1; i >= 0; --i) {
                for (int j = n2; j >= 0; --j) {
                    long long cnt = 0;
                    for (int x = i; x < n1; ++x) {
                        if (word1[x] == target[k])
                            cnt = (cnt + dp[x + 1][j][k + 1]) % MOD;
                    }
                    for (int x = j; x < n2; ++x) {
                        if (word2[x] == target[k])
                            cnt = (cnt + dp[i][x + 1][k + 1]) % MOD;
                    }
                    dp[i][j][k] = cnt;
                }
            }
        }
        return dp[0][0][0];
    }
};