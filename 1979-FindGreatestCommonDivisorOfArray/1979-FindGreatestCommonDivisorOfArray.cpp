// Last updated: 9/5/2026, 12:25:18 AM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int x = INT_MIN, y = INT_MAX;
        for(int n : nums) {
            x = max(x, n);
            y = min(y, n);
        }
        return gcd(x, y);
    }
};