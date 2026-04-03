// Last updated: 4/3/2026, 1:48:24 PM
class Solution {
    long long mod = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1)
                r = (r * b) % mod;
            b = (b * b) % mod;
            e >>= 1;
        }
        return r;
    }
    long long modInverse(long long n) { return power(n, mod - 2); }

public:
    int countVisiblePeople(int n, int pos, int k) {
        if (k < 0 || k > n - 1)
            return 0;

        int N = n - 1, R = k;
        if (R > N / 2)
            R = N - R;
        long long num = 1, den = 1;
        for (int i = 0; i < R; i++) {
            num = (num * (N - i)) % mod;
            den = (den * (i + 1)) % mod;
        }
        long long total = (num * modInverse(den)) % mod;
        return (total * 2) % mod;
    }
};