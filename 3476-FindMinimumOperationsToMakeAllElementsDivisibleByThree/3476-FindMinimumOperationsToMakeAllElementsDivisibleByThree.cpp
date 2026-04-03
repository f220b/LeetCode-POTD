// Last updated: 4/3/2026, 1:51:18 PM
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
