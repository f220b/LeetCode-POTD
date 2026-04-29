// Last updated: 29/4/2026, 10:38:47 pm
1class Solution {
2public:
3    long long maximumScore(vector<vector<int>>& grid) {
4
5        int n = grid.size();
6        int m = grid[0].size();
7        if (m == 1)
8            return 0;
9
10        // prefix sum for each column
11        vector<vector<long long>> col(m, vector<long long>(n + 1, 0));
12        for (int j = 0; j < m; j++) {
13            for (int i = 0; i < n; i++) {
14                col[j][i + 1] = col[j][i] + grid[i][j];
15            }
16        }
17
18        // dp[curr][prev]
19        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
20        vector<vector<long long>> prefMax(n + 1, vector<long long>(n + 1, 0));
21        vector<vector<long long>> suffMax(n + 1, vector<long long>(n + 1, 0));
22
23        for (int c = 1; c < m; c++) {
24
25            vector<vector<long long>> newdp(n + 1, vector<long long>(n + 1, 0));
26
27            for (int curr = 0; curr <= n; curr++) {
28                for (int prev = 0; prev <= n; prev++) {
29
30                    if (curr <= prev) {
31                        long long gain = col[c][prev] - col[c][curr];
32
33                        newdp[curr][prev] =
34                            max(newdp[curr][prev], suffMax[prev][0] + gain);
35                    } else {
36                        long long gain = col[c - 1][curr] - col[c - 1][prev];
37
38                        newdp[curr][prev] =
39                            max({newdp[curr][prev], suffMax[prev][curr],
40                                 prefMax[prev][curr] + gain});
41                    }
42                }
43            }
44
45            // build prefix max & suffix max
46            for (int curr = 0; curr <= n; curr++) {
47
48                prefMax[curr][0] = newdp[curr][0];
49
50                for (int prev = 1; prev <= n; prev++) {
51
52                    long long penalty = 0;
53                    if (prev > curr)
54                        penalty = col[c][prev] - col[c][curr];
55
56                    prefMax[curr][prev] = max(prefMax[curr][prev - 1],
57                                              newdp[curr][prev] - penalty);
58                }
59
60                suffMax[curr][n] = newdp[curr][n];
61
62                for (int prev = n - 1; prev >= 0; prev--) {
63                    suffMax[curr][prev] =
64                        max(suffMax[curr][prev + 1], newdp[curr][prev]);
65                }
66            }
67
68            dp = move(newdp);
69        }
70
71        long long ans = 0;
72        for (int k = 0; k <= n; k++) {
73            ans = max({ans, dp[0][k], dp[n][k]});
74        }
75
76        return ans;
77    }
78};