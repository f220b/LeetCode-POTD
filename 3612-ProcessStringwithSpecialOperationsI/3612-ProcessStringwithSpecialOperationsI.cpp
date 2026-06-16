// Last updated: 17/6/2026, 12:34:18 am
1class Solution {
2public:
3    string processStr(string s) {
4        string res = "";
5        for (char c : s) {
6            if (c == '*') {
7                if (!res.empty())
8                    res.pop_back();
9            } else if (c == '#')
10                res += res;
11            else if (c == '%')
12                reverse(res.begin(), res.end());
13            else
14                res += c;
15        }
16        return res;
17    }
18};