// Last updated: 8/6/2026, 11:41:15 pm
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for (int i = max(1, n - k); i <= n + k; i++) {
            if (!(n & i))
                sum += i;
        }
        return sum;
    }
};