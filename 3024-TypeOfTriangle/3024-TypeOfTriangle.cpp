// Last updated: 9/5/2026, 12:15:37 AM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if ((a + b) > c && (b + c) > a && (a + c) > b) {
            if (a == b && b == c)
                return "equilateral";
            if (a == b || b == c || a == c)
                return "isosceles";
            return "scalene";
        }
        return "none";
    }
};