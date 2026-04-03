// Last updated: 4/3/2026, 1:56:04 PM
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums)
            total += x;
        long long r = total % p;
        if (r == 0)
            return 0;

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long pref = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            pref = (pref + nums[i]) % p;
            long long need = (pref - r + p) % p;

            if (mp.count(need))
                ans = min(ans, i - mp[need]);

            mp[pref] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
