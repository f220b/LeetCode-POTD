// Last updated: 21/4/2026, 9:22:09 pm
1class Solution {
2public:
3    vector<int> rank;
4    vector<int> parent;
5
6    int find(int x) {
7        if (parent[x] != x)
8            parent[x] = find(parent[x]);
9
10        return parent[x];
11    }
12
13    void Union(int x, int y) {
14        int rootX = find(x);
15        int rootY = find(y);
16
17        if (rootX == rootY)
18            return;
19
20        if (rank[rootX] < rank[rootY])
21            swap(rootX, rootY);
22
23        parent[rootY] = rootX;
24        if (rank[rootX] == rank[rootY])
25            rank[rootX]++;
26    }
27
28    int minimumHammingDistance(vector<int>& source, vector<int>& target,
29                               vector<vector<int>>& allowedSwaps) {
30        int n = source.size();
31
32        parent.resize(n);
33        rank.resize(n, 0);
34
35        for (int i = 0; i < n; i++)
36            parent[i] = i;
37
38        for (auto& vec : allowedSwaps)
39            Union(vec[0], vec[1]);
40
41        unordered_map<int, unordered_map<int, int>> groupFreq;
42
43        for (int i = 0; i < n; i++) {
44            int curr = source[i];
45            int parent = find(i);
46            groupFreq[parent][curr]++;
47        }
48
49        int hammingDistance = 0;
50        for (int i = 0; i < n; i++) {
51            int parent = find(i);
52
53            if (groupFreq[parent][target[i]] > 0)
54                groupFreq[parent][target[i]]--;
55            else
56                hammingDistance++;
57        }
58        return hammingDistance;
59    }
60};