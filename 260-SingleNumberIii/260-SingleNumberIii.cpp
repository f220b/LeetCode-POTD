// Last updated: 4/3/2026, 2:00:50 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll = 0;
        for (int i : nums) {
            xorAll ^= i;
        }
        int rightMost = (xorAll & (xorAll - 1)) ^ xorAll;
        int num1 = 0, num2 = 0;
        for (int i : nums) {
            if ((i & rightMost) != 0) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        return {num1, num2};
    }
};