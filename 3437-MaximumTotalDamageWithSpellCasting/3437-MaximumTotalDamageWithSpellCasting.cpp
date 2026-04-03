// Last updated: 4/3/2026, 1:51:27 PM
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> freq;
        for (int x : power)
            freq[x]++;

        vector<long long> vals;
        for (auto& it : freq)
            vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);
        dp[0] = vals[0] * freq[vals[0]];

        for (int i = 1; i < n; i++) {
            long long take = vals[i] * freq[vals[i]];
            int j = i - 1;
            while (j >= 0 && vals[i] - vals[j] <= 2)
                j--;
            if (j >= 0)
                take += dp[j];
            dp[i] = max(dp[i - 1], take);
        }
        return dp[n - 1];
    }
};
