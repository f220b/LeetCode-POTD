// Last updated: 4/3/2026, 1:58:15 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);  // dp[j] = length of longest valid sequence ending at column j

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < j; i++) {
                bool valid = true;
                for(int k = 0; k < n; k++) {
                    if(strs[k][i] > strs[k][j]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int maxSeq = *max_element(dp.begin(), dp.end());
        return m - maxSeq;
    }
};
