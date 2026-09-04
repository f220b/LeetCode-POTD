// Last updated: 9/5/2026, 12:27:37 AM
class Solution {
public:
    int minOperations(string s, char target) {
        int ops = 0;
        for(char ch : s) {
            if(ch != target)
                ops++;
            target = (target == '1') ? '0' : '1';
        }
        return ops;
    }
    int minOperations(string s) {
        return min(minOperations(s, '1'), minOperations(s, '0'));
    }
};