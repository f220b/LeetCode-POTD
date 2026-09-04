// Last updated: 9/5/2026, 12:27:44 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                count++;
        }
        return count <= 1;
    }
};