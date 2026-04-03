// Last updated: 4/3/2026, 1:51:36 PM
class Solution {
public:
    int longestIncreasing(vector<int>& nums) {
        int maxLength = 1, currLength = 1, currptr = 1;
        while (currptr < nums.size()) {
            if (nums[currptr] > nums[currptr - 1]) {
                currLength++;
            } else {
                currLength = 1;
            }
            maxLength = max(maxLength, currLength);
            currptr++;
        }
        return maxLength;
    }
    int longestDecreasing(vector<int>& nums) {
        int maxLength = 1, currLength = 1, currptr = 1;
        while (currptr < nums.size()) {
            if (nums[currptr] < nums[currptr - 1]) {
                currLength++;
            } else {
                currLength = 1;
            }
            maxLength = max(maxLength, currLength);
            currptr++;
        }
        return maxLength;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(longestIncreasing(nums), longestDecreasing(nums));
    }
};