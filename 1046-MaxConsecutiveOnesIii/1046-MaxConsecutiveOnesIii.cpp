// Last updated: 4/3/2026, 1:58:04 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, maxLen = 0;
        int zerosCount = 0;
        
        while(right < nums.size()) {
            if(nums[right] == 0) {
                zerosCount++;
            }
            while(zerosCount > k) {
                if(nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
