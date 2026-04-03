// Last updated: 4/3/2026, 2:00:07 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int i : nums) {
            if (i == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};