// Last updated: 4/3/2026, 1:49:22 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long maxLen = 0, n = nums.size(), left = 0, right = 0;
        if(n == 1)
            return 0;
        
        while(right < n) {
            if(nums[right] <= (long long)k * nums[left]) 
                maxLen = max(maxLen, right-left+1);
            while(nums[right] > (long long)k * nums[left])
                left++;
            right++;
        }
        return n - maxLen;
    }
};