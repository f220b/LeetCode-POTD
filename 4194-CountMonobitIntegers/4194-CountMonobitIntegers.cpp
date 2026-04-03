// Last updated: 4/3/2026, 1:48:44 PM
class Solution {
public:
    int countMonobit(int n) {
        if (n == 0)
            return 1;

        int count = 1;
        long long current = 1;
        while (current <= n) {
            count++;
            current = (current << 1) | 1;
        }
        return count;
    }
};