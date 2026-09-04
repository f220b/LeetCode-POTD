// Last updated: 9/5/2026, 12:01:14 AM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroes = 0;

        for (int x : nums) {
            if (x == 0)
                zeroes++;
        }

        int swaps = 0;
        for (int i = n - zeroes; i < n; i++) {
            if (nums[i] != 0)
                swaps++;
        }
        return swaps;
    }
};