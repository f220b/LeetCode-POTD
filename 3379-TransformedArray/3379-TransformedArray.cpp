// Last updated: 9/5/2026, 12:11:33 AM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int j = (i + nums[i]) % n;
            if (j < 0)
                j += n;
            result[i] = nums[j];
        }
        return result;
    }
};