// Last updated: 4/3/2026, 1:50:32 PM
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