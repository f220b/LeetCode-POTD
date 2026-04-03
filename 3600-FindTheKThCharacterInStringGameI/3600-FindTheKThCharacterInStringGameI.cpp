// Last updated: 4/3/2026, 1:51:01 PM
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