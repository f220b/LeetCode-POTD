// Last updated: 4/3/2026, 2:01:54 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = INT_MIN;
        int suffix = 1, prefix = 1, n = nums.size();

        for (int i = 0; i < n; i++) {
            suffix = suffix == 0 ? nums[i] : suffix * nums[i];
            prefix = prefix == 0 ? nums[n - i - 1] : prefix * nums[n - i - 1];
            maxPro = max(maxPro, max(suffix, prefix));
        }
        return maxPro;
    }
};