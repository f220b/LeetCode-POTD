// Last updated: 4/3/2026, 1:51:00 PM
class Solution {
public:
    char kthChar(long long k, vector<int>& operations, int idx) {
        if (idx < 0 || k == 1)
            return 'a';

        long long mid = 1LL << idx;
        if (k > mid) {
            char ch = kthChar(k - mid, operations, idx - 1);
            if (operations[idx] == 1)
                return (ch - 'a' + 1) % 26 + 'a';
            return ch;
        }
        return kthChar(k, operations, idx - 1);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        int idx = 0;
        while ((1LL << idx) < k)
            idx++;
            
        return kthChar(k, operations, idx - 1);
    }
};