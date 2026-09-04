// Last updated: 9/5/2026, 12:07:01 AM
class Solution {
public:
    int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            for (int i = l; i <= r; i += k)
                nums[i] = ((long long)nums[i] * v) % mod;
        }
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
};