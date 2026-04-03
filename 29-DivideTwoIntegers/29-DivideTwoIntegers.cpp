// Last updated: 4/3/2026, 2:04:12 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case: overflow when dividend is INT_MIN and divisor is -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Return INT_MAX to prevent overflow

        // Handle edge cases for zero division or if dividend equals divisor
        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;

        // Determine the sign of the result
        bool sign = (dividend > 0) == (divisor > 0);

        // Convert to long to handle edge cases with abs(INT_MIN)
        long num = abs((long)dividend);
        long den = abs((long)divisor);
        long quotient = 0;

        // Perform division using bitwise operations
        while (num >= den) {
            int count = 0;
            while (num >= (den << (count + 1))) {
                count++;
            }
            quotient += 1 << count;
            num -= (den << count);
        }

        // Handle overflow cases and return result
        if (quotient > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }

        // Return the final result with the correct sign, ensuring no overflow
        if (!sign && quotient == INT_MIN) {
            return INT_MIN; // Return directly if result is INT_MIN
        }

        return sign ? (int)quotient : -(int)quotient;
    }
};
