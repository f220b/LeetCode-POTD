// Last updated: 4/3/2026, 1:54:00 PM
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