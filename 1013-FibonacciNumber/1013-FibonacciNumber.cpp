// Last updated: 4/3/2026, 1:58:12 PM
class Solution {
public:
    int fib(int n) {
        // Time Complexity O(n)
        if (n <= 1)
            return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};