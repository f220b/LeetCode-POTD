// Last updated: 4/3/2026, 2:00:05 PM
class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1;
        k -= 1;

        while (k > 0) {
            long steps = countSteps(cur, n);
            if (steps <= k) {
                cur += 1;
                k -= steps;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return (int)cur;
    }

    long countSteps(long prefix, long n) {
        long steps = 0;
        long first = prefix, last = prefix;

        while (first <= n) {
            steps += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }
};
