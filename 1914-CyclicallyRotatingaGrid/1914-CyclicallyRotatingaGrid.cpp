// Last updated: 9/5/2026, 7:17:49 pm
1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int numLayers = min(m, n) / 2;
7
8        for (int i = 0; i < numLayers; i++) {
9            vector<int> temp;
10
11            for (int j = i; j < n - 1 - i; j++)
12                temp.push_back(grid[i][j]);
13            for (int j = i; j < m - 1 - i; j++)
14                temp.push_back(grid[j][n - 1 - i]);
15            for (int j = n - 1 - i; j > i; j--)
16                temp.push_back(grid[m - 1 - i][j]);
17            for (int j = m - 1 - i; j > i; j--)
18                temp.push_back(grid[j][i]);
19
20            int len = temp.size();
21            int shift = k % len;
22            int idx = shift;
23
24            for (int j = i; j < n - 1 - i; j++) {
25                grid[i][j] = temp[idx % len];
26                idx++;
27            }
28            for (int j = i; j < m - 1 - i; j++) {
29                grid[j][n - 1 - i] = temp[idx % len];
30                idx++;
31            }
32            for (int j = n - 1 - i; j > i; j--) {
33                grid[m - 1 - i][j] = temp[idx % len];
34                idx++;
35            }
36            for (int j = m - 1 - i; j > i; j--) {
37                grid[j][i] = temp[idx % len];
38                idx++;
39            }
40        }
41
42        return grid;
43    }
44};