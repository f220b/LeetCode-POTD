// Last updated: 9/5/2026, 12:01:30 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int minOps = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y)
                    continue;

                int ops = 0;
                for (int i = 0; i < n; i++) {
                    int target = x;
                    if (i & 1)
                        target = y;

                    int curr = nums[i] % k;
                    int diff = abs(curr - target);
                    ops += min(diff, k - diff);
                }
                minOps = min(minOps, ops);
            }
        }
        return minOps;
    }
};