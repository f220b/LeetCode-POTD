// Last updated: 9/5/2026, 12:13:56 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int x : nums) {
            int r = x % 3;
            if (r == 1 || r == 2)
                ops += 1;
        }
        return ops;
    }
};
