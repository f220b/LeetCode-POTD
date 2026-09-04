// Last updated: 9/5/2026, 12:08:52 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        
        return sum % k;
    }
};