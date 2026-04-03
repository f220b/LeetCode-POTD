// Last updated: 4/3/2026, 1:55:45 PM
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = 0;
        total += (weeks * (weeks - 1) / 2) * 7 + weeks * 28;
        total += days * (2 * weeks + days + 1) / 2;
        return total;
    }
};
