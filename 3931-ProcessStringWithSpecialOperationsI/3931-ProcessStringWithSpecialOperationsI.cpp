// Last updated: 7/3/2026, 10:26:09 AM
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (char c : s) {
            if (c == '*') {
                if (!res.empty())
                    res.pop_back();
            } else if (c == '#')
                res += res;
            else if (c == '%')
                reverse(res.begin(), res.end());
            else
                res += c;
        }
        return res;
    }
};