// Last updated: 11/4/2026, 11:25:50 pm
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