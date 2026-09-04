// Last updated: 9/5/2026, 12:05:08 AM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};