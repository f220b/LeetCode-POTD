// Last updated: 4/3/2026, 1:50:42 PM
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> mat(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                mat[i][(i + j) % 26]++;
            }
        }

        auto multiply = [&](vector<vector<long long>>& A,
                            vector<vector<long long>>& B) {
            vector<vector<long long>> C(26, vector<long long>(26, 0));
            for (int i = 0; i < 26; i++) {
                for (int k = 0; k < 26; k++) {
                    if (A[i][k] == 0)
                        continue;
                    for (int j = 0; j < 26; j++) {
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return C;
        };

        auto power = [&](vector<vector<long long>> base, long long exp) {
            vector<vector<long long>> res(26, vector<long long>(26, 0));
            for (int i = 0; i < 26; i++)
                res[i][i] = 1;
            while (exp > 0) {
                if (exp & 1)
                    res = multiply(res, base);
                base = multiply(base, base);
                exp >>= 1;
            }
            return res;
        };

        vector<vector<long long>> trans = power(mat, t);
        vector<long long> dp(26, 0);
        for (char c : s)
            dp[c - 'a']++;

        vector<long long> finalCnt(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                finalCnt[j] = (finalCnt[j] + dp[i] * trans[i][j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long x : finalCnt)
            ans = (ans + x) % MOD;
        return ans;
    }
};
