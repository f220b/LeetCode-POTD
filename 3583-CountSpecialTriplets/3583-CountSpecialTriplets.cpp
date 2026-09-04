// Last updated: 9/5/2026, 12:08:16 AM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;

        for (int x : nums)
            right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            right[x]--;

            long long need = 2 * 1LL * x;

            long long L = left[need];
            long long R = right[need];

            ans = (ans + (L * R) % MOD) % MOD;

            left[x]++;
        }
        return ans;
    }
};
