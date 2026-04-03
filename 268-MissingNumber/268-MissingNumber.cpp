// Last updated: 4/3/2026, 2:00:47 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = 0, expectSum = 0;
        for (int num : nums)
            actualSum += num;
        expectSum = (n * (n + 1)) / 2;
        return expectSum - actualSum;
    }
};