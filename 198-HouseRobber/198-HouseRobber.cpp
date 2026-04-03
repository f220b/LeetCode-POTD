// Last updated: 4/3/2026, 2:01:30 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[0] = prev[1];
            curr[1] = max(prev[1], nums[i] + prev[0]);
            prev = curr;
        }
        return prev[1];
    }
};