// Last updated: 4/3/2026, 1:55:15 PM
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int orr = 0;
        for (int ele : nums)
            orr |= ele;
        return orr * (1 << (n - 1));
    }
};