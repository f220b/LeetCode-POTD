// Last updated: 4/3/2026, 1:54:56 PM
class Solution {
public:
    int mod = 1000000007;
    long long binaryExponentiation(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (binaryExponentiation(4, n / 2) *
                binaryExponentiation(5, n - (n / 2))) %
               mod;
    }
};