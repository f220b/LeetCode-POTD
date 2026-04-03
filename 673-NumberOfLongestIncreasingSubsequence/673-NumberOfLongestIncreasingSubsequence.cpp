// Last updated: 4/3/2026, 1:59:27 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> count(n, 1);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    if (lis[i] < 1 + lis[prev]) {
                        lis[i] = 1 + lis[prev];
                        count[i] = count[prev];
                    } else if (lis[i] == 1 + lis[prev]) {
                        count[i] += count[prev];
                    }
                }
            }
            maxLen = max(maxLen, lis[i]);
        }
        int total = 0;
        for (int i = 0; i < n; i++)
            if (lis[i] == maxLen)
                total += count[i];

        return total;
    }
};