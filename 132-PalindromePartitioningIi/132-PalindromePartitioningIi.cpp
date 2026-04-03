// Last updated: 4/3/2026, 2:02:13 PM
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                int cuts = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (pal[j + 1][i]) {
                        cuts = min(cuts, dp[j] + 1);
                    }
                }
                dp[i] = cuts;
            }
        }

        return dp[n - 1];
    }
};
