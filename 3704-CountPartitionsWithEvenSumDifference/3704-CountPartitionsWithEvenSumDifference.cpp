// Last updated: 4/3/2026, 1:50:19 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;
        
        int leftSum = 0, count = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;
            if(abs(rightSum - leftSum) % 2 == 0)
                count++;
        }
        return count;
    }
};