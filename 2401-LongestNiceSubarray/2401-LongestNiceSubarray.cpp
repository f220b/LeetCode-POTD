// Last updated: 9/5/2026, 12:20:53 AM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int currSum = 0, xorSum = 0;
        int maxWindow = 0;
        while (right < nums.size()) {
            currSum += nums[right];
            xorSum ^= nums[right];
            while(xorSum != currSum) {
                currSum -= nums[left];
                xorSum ^= nums[left];
                left++;
            }
            maxWindow = max(maxWindow, right - left + 1);
            right++;
        }
        return maxWindow;
    }
};