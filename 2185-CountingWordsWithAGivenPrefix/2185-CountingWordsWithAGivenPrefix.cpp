// Last updated: 9/5/2026, 12:22:32 AM
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int len = pref.length();
        for (string str : words) {
            if (str.substr(0, len) == pref)
                count++;
        }
        return count;
    }
};