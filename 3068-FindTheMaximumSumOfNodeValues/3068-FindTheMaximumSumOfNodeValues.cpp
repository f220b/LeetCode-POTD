// Last updated: 9/5/2026, 12:15:44 AM
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long baseSum = 0;
        int minDiff = INT_MAX;
        int countPositive = 0;
        long long totalGain = 0;

        for (int x : nums) {
            int flipped = x ^ k;
            int diff = flipped - x;
            baseSum += x;
            if (diff > 0) {
                totalGain += diff;
                countPositive++;
            }
            minDiff = min(minDiff, abs(diff));
        }

        if (countPositive % 2 == 0) {
            return baseSum + totalGain;
        } else {
            return baseSum + totalGain - minDiff;
        }
    }
};
