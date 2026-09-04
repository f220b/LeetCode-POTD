// Last updated: 9/5/2026, 12:00:34 AM
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n >> 1, cnt = 0;

        for (int i : nums) {
            if (i == nums[mid])
                cnt++;
        }
        return cnt == 1;
    }
};