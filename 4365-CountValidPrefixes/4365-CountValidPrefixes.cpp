// Last updated: 8/6/2026, 12:57:23 PM
class Solution {
public:
    int countValidPrefixes(string s) {
        int maxCount = 0;
        vector<int> ch(2, 0);
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            maxCount = max(++ch[s[i] - '0'], maxCount);
            int len = i + 1;
            if ((len & 1) && (maxCount <= (len >> 1) + 1))
                cnt++;
            else if (!(len & 1) && (maxCount <= (len >> 1)))
                cnt++;
        }
        return cnt;
    }
};