// Last updated: 4/3/2026, 1:48:53 PM
class Solution {
public:
    long long C[61][61];
    void precompute() {
        for (int i = 0; i <= 60; i++) {
            for (int j = 0; j <= 60; j++)
                C[i][j] = 0;
        }
        for (int i = 0; i <= 60; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    long long countKBits(long long x, int k) {
        if (k < 0)
            return 0;

        int currK = k;
        long long total = 0;
        for (int i = 60; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (currK <= i)
                    total += C[i][currK];
                currK--;
                if (currK < 0)
                    break;
            }
        }
        if (currK == 0)
            total++;
        return total;
    }
    long long nthSmallest(long long n, int k) {
        if (k < 0)
            return 0;

        precompute();
        long long low = 1;
        long long high = (1LL << 60) - 1;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countKBits(mid, k) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};