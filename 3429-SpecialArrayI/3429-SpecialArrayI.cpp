// Last updated: 4/3/2026, 1:51:31 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i =1;i<nums.size();i++){
            if(nums[i]%2==0&&nums[i-1]%2==0)
            return false;
            else if(nums[i]%2!=0&&nums[i-1]%2!=0)
            return false;      
        }
        return true;
    }
};