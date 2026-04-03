// Last updated: 4/3/2026, 1:49:17 PM
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (auto& i : queries) {
            int l = i[0], r = i[1], k = i[2], v = i[3];
            for (int idx = l; idx <= r; idx += k)
                nums[idx] = (1LL * nums[idx] * v) % MOD;
        }
        int result = 0;
        for (int x : nums)
            result ^= x;
        return result;
    }
};