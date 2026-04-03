// Last updated: 4/3/2026, 1:59:51 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int num : nums)
            total += num;
        // S1 - S2 = target
        // S1 = (total + target) / 2
        if (abs(target) > total || (total + target) % 2 != 0)
            return 0;
        int newTarget = (total + target) / 2;
        vector<int> prev(newTarget + 1, 0);
        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= newTarget)
            prev[nums[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            vector<int> curr(newTarget + 1, 0);
            for (int currSum = 0; currSum <= newTarget; currSum++) {
                int pick = 0;
                if (currSum >= nums[ind])
                    pick = prev[currSum - nums[ind]];
                int notPick = prev[currSum];
                curr[currSum] = (pick + notPick);
            }
            prev = curr;
        }
        return prev[newTarget];
    }
};