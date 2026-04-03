// Last updated: 4/3/2026, 1:51:50 PM
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
