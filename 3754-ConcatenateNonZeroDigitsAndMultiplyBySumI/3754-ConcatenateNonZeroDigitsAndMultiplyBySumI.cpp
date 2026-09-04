// Last updated: 9/5/2026, 12:04:55 AM
class Solution {
public:
    using ll = long long;
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0;
        int mul = 1;

        while (n) {
            int d = n % 10;
            if (d) {
                x = x + (d * mul);
                mul *= 10;
            }
            sum += d;
            n /= 10;
        }
        return (ll)x * sum;
    }
};