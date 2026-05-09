// Last updated: 9/5/2026, 8:37:28 pm
1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.length();
5        if (n < 3)
6            return 0;
7
8        int ones = 0, zeroes = 0;
9        for (char ch : s) {
10            if (ch == '1')
11                ones++;
12            else
13                zeroes++;
14        }
15        if (ones == 0)
16            return 0;
17
18        int flips = 0;
19        if (s[0] == '1' && s[n - 1] == '1')
20            flips = ones - 2;
21        else if (s[0] == '1' || s[n - 1] == '1')
22            flips = ones;
23        else
24            flips = ones + 2;
25        return min({zeroes, flips, ones - 1});
26    }
27};