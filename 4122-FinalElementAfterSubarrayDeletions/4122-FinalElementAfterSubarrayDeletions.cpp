// Last updated: 4/3/2026, 1:48:58 PM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};