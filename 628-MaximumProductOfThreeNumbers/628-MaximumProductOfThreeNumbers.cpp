// Last updated: 8/6/2026, 1:21:38 PM
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxPro = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int temp = nums[0] * nums[1];
        if (nums[n - 1] > 0)
            maxPro = max(maxPro, temp * nums[n - 1]);
        
        return maxPro;
    }
};