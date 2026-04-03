// Last updated: 4/3/2026, 1:49:46 PM
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 2, 0);
        dp[0] = 1;
        pref[1] = 1;

        deque<int> mn, mx;
        int L = 0;

        for (int R = 0; R < n; R++) {

            while (!mn.empty() && nums[mn.back()] > nums[R])
                mn.pop_back();
            mn.push_back(R);

            while (!mx.empty() && nums[mx.back()] < nums[R])
                mx.pop_back();
            mx.push_back(R);

            while (nums[mx.front()] - nums[mn.front()] > k) {
                if (mn.front() == L)
                    mn.pop_front();
                if (mx.front() == L)
                    mx.pop_front();
                L++;
            }

            dp[R + 1] = (pref[R + 1] - pref[L] + MOD) % MOD;
            pref[R + 2] = (pref[R + 1] + dp[R + 1]) % MOD;
        }
        return dp[n];
    }
};
