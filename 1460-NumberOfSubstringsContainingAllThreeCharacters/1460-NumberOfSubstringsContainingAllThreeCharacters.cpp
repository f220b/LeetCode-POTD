// Last updated: 4/3/2026, 1:56:58 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> abc(3, -1);
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            abc[s[i] - 'a'] = i;
            count += min(abc[0], min(abc[1], abc[2])) + 1;
        }
        return count;
    }
};