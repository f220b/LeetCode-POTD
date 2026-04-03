// Last updated: 4/3/2026, 1:53:26 PM
class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> sumOfDigits;
        for (int num : nums) {
            int sum = getDigitSum(num);

            if (num > sumOfDigits[sum].first) {
                sumOfDigits[sum].second = sumOfDigits[sum].first;
                sumOfDigits[sum].first = num;
            } else if (num > sumOfDigits[sum].second) {
                sumOfDigits[sum].second = num;
            }
        }
        int maxSum = -1;
        for (auto& i : sumOfDigits) {
            pair<int, int> numbers = i.second;
            if (numbers.second > 0) {
                maxSum = max(maxSum, numbers.first + numbers.second);
            }
        }
        return maxSum;
    }
};