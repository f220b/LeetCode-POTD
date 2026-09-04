// Last updated: 9/5/2026, 12:31:29 AM
class Solution {
public:
    int findDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mpp;
        int maxSize = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int digitSum = findDigitSum(i);
            mpp[digitSum]++;
            if (mpp[digitSum] == maxSize) {
                count++;
            } else if (mpp[digitSum] > maxSize) {
                maxSize = mpp[digitSum];
                count = 1;
            }
        }
        return count;
    }
};