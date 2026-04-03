// Last updated: 4/3/2026, 1:49:45 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        
        return sum % k;
    }
};