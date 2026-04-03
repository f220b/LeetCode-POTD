// Last updated: 4/3/2026, 1:50:54 PM
class Solution {
public:
    bool simulate(int start, int dir, vector<int> nums) {
        int n = nums.size();
        int curr = start;
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir;
            } else {
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for (int x : nums)
            if (x != 0)
                return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(i, 1, nums))
                    count++;
                if (simulate(i, -1, nums))
                    count++;
            }
        }
        return count;
    }
};