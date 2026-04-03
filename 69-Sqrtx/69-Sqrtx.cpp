// Last updated: 4/3/2026, 2:03:22 PM
class Solution {
public:
    int mySqrt(int x) {
        // Binary Search
        if (x < 2)
            return x;
        int lp = 2, rp = x / 2;
        while (lp <= rp) {
            int mid = lp + (rp - lp) / 2;
            long square = (long)mid * mid; // To prevent overflow
            // By casting mid to long long before performing the multiplication
            // Multiplication is done using long long arithmetic.
            if (square == x)
                return mid;
            else if (square < x)
                lp = mid + 1;
            else
                rp = mid - 1;
        }
        return rp;
        // Right pointer will store the floor value
    }
};