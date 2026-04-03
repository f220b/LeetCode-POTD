// Last updated: 4/3/2026, 2:02:14 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            ans ^= i;
            // n^n=0
            // n^0=n
        }
        return ans;
    }
};