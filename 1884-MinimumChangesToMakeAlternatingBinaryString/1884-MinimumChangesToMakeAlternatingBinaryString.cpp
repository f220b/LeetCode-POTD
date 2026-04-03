// Last updated: 4/3/2026, 1:55:31 PM
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