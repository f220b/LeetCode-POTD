// Last updated: 9/5/2026, 12:28:23 AM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        unordered_map<int, int> mpp;
        int maxVal = 0, currVal = 0;

        while (right < n) {
            mpp[nums[right]]++;

            while (left <= right && mpp[nums[right]] > 1) {
                mpp[nums[left]]--;
                currVal -= nums[left];
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }
            currVal += nums[right];
            maxVal = max(currVal, maxVal);
            right++;
        }
        return maxVal;
    }
};