// Last updated: 9/5/2026, 12:04:03 AM
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