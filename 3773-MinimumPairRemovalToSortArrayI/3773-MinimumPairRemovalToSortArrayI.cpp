// Last updated: 4/3/2026, 1:50:01 PM
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (true) {
            bool ok = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return ops;

            int n = nums.size();
            int minSum = INT_MAX, idx = 0;
            for (int i = 0; i < n - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (i == idx) {
                    temp.push_back(nums[i] + nums[i + 1]);
                    i++;
                } else {
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            ops++;
        }
        return -1;
    }
};
