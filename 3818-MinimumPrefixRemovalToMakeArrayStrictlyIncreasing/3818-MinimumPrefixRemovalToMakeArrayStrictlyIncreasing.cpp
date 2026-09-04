// Last updated: 9/5/2026, 12:03:59 AM
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        bool flag = false;
        int idx = 0;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] >= nums[i+1]) {
                flag = true;
                idx = i;
                break;
            }
        }
        if(flag)
            return idx+1;
        return 0;
    }
};