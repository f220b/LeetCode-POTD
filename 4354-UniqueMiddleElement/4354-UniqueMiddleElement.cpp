// Last updated: 7/6/2026, 8:50:47 AM
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