// Last updated: 9/5/2026, 12:21:54 AM
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        long long leftSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum)
                count++;
        }
        return count;
    }
};