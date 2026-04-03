// Last updated: 4/3/2026, 1:48:32 PM
class Solution {
public:
    bool alreadySorted(string& s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] < s[i - 1])
                return false;
        }
        return true;
    }
    int minOperations(string s) {
        if (alreadySorted(s))
            return 0;
        int n = s.length();
        if (n == 2)
            return -1;
        char minChar = 'z' + 1, maxChar = 'a' - 1;
        for (char ch : s) {
            if (ch < minChar)
                minChar = ch;
            if (ch > maxChar)
                maxChar = ch;
        }
        if(s[0] == minChar || s[n-1] == maxChar)
            return 1;
        
        bool maxCondition = false, minCondition = false;
        for (int i = 0; i < n - 1; i++) {
            if (minChar == s[i])
                minCondition = true;
            if (maxChar == s[i + 1])
                maxCondition = true;
        }
        if(maxCondition || minCondition)
            return 2;
        return 3;
    }
};