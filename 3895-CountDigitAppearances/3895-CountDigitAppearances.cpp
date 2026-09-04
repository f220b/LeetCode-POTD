// Last updated: 9/5/2026, 12:02:12 AM
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for (int num : nums) {
            int temp = num;
            while (temp > 0) {
                if (temp % 10 == digit)
                    count++;
                temp /= 10;
            }
        }
        return count;
    }
};