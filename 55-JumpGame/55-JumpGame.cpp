// Last updated: 4/3/2026, 2:03:40 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (maxJump < i) {
                return false;
            }
            maxJump = max(maxJump, i + nums[i]);

            if (maxJump >= (n - 1))
                return true;
        }

        return true;
    }
};