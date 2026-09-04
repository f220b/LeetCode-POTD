// Last updated: 9/5/2026, 12:27:35 AM
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