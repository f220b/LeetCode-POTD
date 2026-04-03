// Last updated: 4/3/2026, 2:03:48 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        ;
        int jumps = 0;

        while (right < n - 1) {
            int maxReach = 0;
            for (int i = left; i <= right; i++) {
                maxReach = max(maxReach, i + nums[i]);
            }
            left = right + 1;
            right = maxReach;
            jumps++;
        }
        return jumps;
    }
};