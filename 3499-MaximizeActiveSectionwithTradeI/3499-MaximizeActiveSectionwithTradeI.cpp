// Last updated: 7/21/2026, 6:00:14 PM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        s = "1" + s + "1";
5
6        int n = s.size();
7        int totalOnes = -2; // ignore the two added boundary 1's
8
9        int i = 0;
10        int lastZero = 0, one = 0, currZero = 0;
11        int ans = 0;
12
13        while (i < n) {
14            char ch = s[i];
15            int len = 0;
16            while (i < n && s[i] == ch) {
17                len++;
18                i++;
19            }
20
21            if (ch == '1') {
22                totalOnes += len;
23                one = len;
24            } else {
25                currZero = len;
26
27                if (lastZero > 0 && one > 0) {
28                    ans = max(ans, lastZero + currZero);
29                }
30
31                lastZero = currZero;
32                one = 0;
33            }
34        }
35
36        return totalOnes + ans;
37    }
38};
39