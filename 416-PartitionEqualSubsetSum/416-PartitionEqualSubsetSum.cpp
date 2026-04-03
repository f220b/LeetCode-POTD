// Last updated: 4/3/2026, 2:00:12 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<bool> prev(sum + 1, false);
        prev[sum] = true;

        for (int i = 0; i < n; i++) {
            vector<bool> curr(sum + 1, false);
            for (int currSum = sum; currSum >= 0; currSum--) {
                bool pick = false;
                if (currSum + nums[i] <= sum)
                    pick = prev[currSum + nums[i]];
                bool notPick = prev[currSum];

                curr[currSum] = (pick || notPick);
            }
            prev = curr;
        }
        return prev[0];
    }
};