// Last updated: 8/6/2026, 1:15:33 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = -1, b = -1;
        for (int x : nums) {
            if (x >= a) {
                b = a;
                a = x;
            } else if (x >= b) {
                b = x;
            }
        }
        return (a - 1) * (b - 1);
    }
};