// Last updated: 9/5/2026, 12:03:37 AM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(), count = 0, sum = 0;
        for (int i = n - 1; i > 0; i--) {
            sum += nums[i];
            double average = (double)sum / (n - i);
            if (nums[i - 1] > average)
                count++;
        }
        return count;
    }
};