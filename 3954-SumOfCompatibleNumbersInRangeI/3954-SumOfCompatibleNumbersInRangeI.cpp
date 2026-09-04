// Last updated: 9/5/2026, 12:01:10 AM
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