// Last updated: 20/4/2026, 6:53:46 pm
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int maxDist = 0;
6
7        for (int i = n - 1; i >= 0; --i) {
8            if (colors[i] != colors[0]) {
9                maxDist = max(maxDist, i);
10                break;
11            }
12        }
13
14        for (int i = 0; i < n; ++i) {
15            if (colors[i] != colors[n - 1]) {
16                maxDist = max(maxDist, (n - 1) - i);
17                break;
18            }
19        }
20
21        return maxDist;
22    }
23};