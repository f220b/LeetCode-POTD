// Last updated: 4/3/2026, 1:54:34 PM
class Solution {
public:
    int countSubsets(int idx, int curr_OR, vector<int>& nums, int max_OR) {
        if (idx == nums.size()) {
            if (curr_OR == max_OR)
                return 1;
            return 0;
        }
        int take = countSubsets(idx + 1, curr_OR | nums[idx], nums, max_OR);
        int not_take = countSubsets(idx + 1, curr_OR, nums, max_OR);

        return take + not_take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_OR = 0;
        for (int num : nums)
            max_OR |= num;

        int curr_OR = 0;
        return countSubsets(0, curr_OR, nums, max_OR);
    }
};