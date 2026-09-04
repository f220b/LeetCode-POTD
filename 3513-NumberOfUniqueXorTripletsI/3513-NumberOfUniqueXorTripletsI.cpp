// Last updated: 9/5/2026, 12:09:19 AM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int msb = log2(n);
        return pow(2, msb + 1);
    }
};