// Last updated: 4/3/2026, 1:49:19 PM
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

        vector<long long> dp(n + 1, 0);
        vector<long long> minDpForResidue(k, LLONG_MAX);
        minDpForResidue[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];

            int residue = prefixSum[i] % k;
            if (minDpForResidue[residue] != LLONG_MAX) {
                if (minDpForResidue[residue] < dp[i])
                    dp[i] = minDpForResidue[residue];
            }
            if (dp[i] < minDpForResidue[residue])
                minDpForResidue[residue] = dp[i];
        }
        return dp[n];
    }
};