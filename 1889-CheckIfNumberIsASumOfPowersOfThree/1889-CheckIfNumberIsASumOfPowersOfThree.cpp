// Last updated: 4/3/2026, 1:55:29 PM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int n1 = n;
        while (n1) {
            int dig = n1 % 3;
            if (dig == 2) {
                return false;
            }
            n1 /= 3;
        }
        return true;
    }
};