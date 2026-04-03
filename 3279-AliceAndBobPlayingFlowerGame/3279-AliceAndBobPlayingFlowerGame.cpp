// Last updated: 4/3/2026, 1:51:51 PM
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long total = 0;
        // For Alice to win, (x + y) must be odd
        // If x is even, every odd from [1, m] makes a pair
        // If y is even, every odd from [1, n] makes a pair

        // Case 1:
        // Evens from x and Odds from y
        long long evenX = floor((double)n / 2);
        long long oddY = ceil((double)m / 2);
        total += (evenX * oddY);

        // Case 2:
        // Evens from y and Odds from x
        long long oddX = ceil((double)n / 2);
        long long evenY = floor((double)m / 2);
        total += (oddX * evenY);

        return total;
    }
};