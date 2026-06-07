// Last updated: 7/6/2026, 8:15:23 am
1class Solution {
2public:
3    vector<string> result;
4    void solve(int i, int hasOne, string str, int n, int k) {
5        if (i == n) {
6            if (k >= 0)
7                result.push_back(str);
8            return;
9        }
10        solve(i + 1, 0, str + '0', n, k);
11
12        if (!hasOne && k >= i)
13            solve(i + 1, 1, str + '1', n, k - i);
14    }
15    vector<string> generateValidStrings(int n, int k) {
16        solve(0, 0, "", n, k);
17        return result;
18    }
19};