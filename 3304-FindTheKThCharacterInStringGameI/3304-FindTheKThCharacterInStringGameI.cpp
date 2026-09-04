// Last updated: 9/5/2026, 12:13:06 AM
class Solution {
public:
    char kthCharacter(int k) {
        int pos = k - 1;
        int cnt = 0;
        while (pos) {
            pos &= (pos - 1);
            cnt++;
        }
        return 'a' + (cnt % 26);
    }
};