// Last updated: 4/3/2026, 1:54:33 PM
class Solution {
public:
    bool isBeautiful(int num) {
        vector<int> count(10, 0);
        int x = num;
        while (x) {
            count[x % 10]++;
            x /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (count[i] && count[i] != i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1;; i++) {
            if (isBeautiful(i))
                return i;
        }
    }
};
