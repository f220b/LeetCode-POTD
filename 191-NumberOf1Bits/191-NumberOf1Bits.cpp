// Last updated: 4/3/2026, 2:01:32 PM
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};