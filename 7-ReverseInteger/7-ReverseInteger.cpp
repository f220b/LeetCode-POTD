// Last updated: 4/3/2026, 2:04:37 PM
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int dig = x % 10;
            if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
                return 0;
                // Return 0 if reversing x would cause overflow/underflow
            }
            rev = (rev * 10) + dig;
            x /= 10;
        }
        return rev;
    }
};