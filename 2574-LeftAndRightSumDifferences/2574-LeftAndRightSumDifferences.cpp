// Last updated: 9/5/2026, 12:18:42 AM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int leftSum = 0, rightSum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int i = 0; i < n; i++) {
            rightSum = totalSum - (leftSum + nums[i]);
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};