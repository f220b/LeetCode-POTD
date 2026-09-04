// Last updated: 9/5/2026, 12:16:05 AM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        return res + min1 + min2;
    }
};