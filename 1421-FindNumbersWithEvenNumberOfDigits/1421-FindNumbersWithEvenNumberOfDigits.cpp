// Last updated: 4/3/2026, 1:57:09 PM
class Solution {
public:
    bool isEvenDigits(int num) {
        int count = 0;
        while (num) {
            count++;
            num /= 10;
        }
        return count % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (isEvenDigits(num)) {
                count++;
            }
        }
        return count;
    }
};