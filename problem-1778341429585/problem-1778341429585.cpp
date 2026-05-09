// Last updated: 9/5/2026, 9:13:49 pm
1class Solution {
2public:
3    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
4                         int target, int k) {
5        vector<vector<pair<int, int>>> adj(n);
6        int maxWeight = 0;
7        for (auto edge : edges) {
8            adj[edge[0]].push_back({edge[1], edge[2]});
9            adj[edge[1]].push_back({edge[0], edge[2]});
10            maxWeight = max(maxWeight, edge[2]);
11        }
12
13        int low = 0, high = maxWeight;
14        int ans = -1;
15        while (low <= high) {
16            int mid = low + ((high - low) >> 1);
17            vector<int> dist(n, 1e9);
18            deque<int> dq;
19
20            dist[source] = 0;
21            dq.push_back(source);
22            while (!dq.empty()) {
23                int u = dq.front();
24                dq.pop_front();
25
26                if (u == target && dist[u] <= k)
27                    break;
28
29                for (auto edge : adj[u]) {
30                    int v = edge.first;
31                    int w = edge.second;
32                    int cost = (w > mid) ? 1 : 0;
33
34                    if (dist[u] + cost < dist[v]) {
35                        dist[v] = dist[u] + cost;
36                        if (cost == 0)
37                            dq.push_front(v);
38                        else
39                            dq.push_back(v);
40                    }
41                }
42            }
43            if (dist[target] <= k) {
44                ans = mid;
45                high = mid - 1;
46            } else {
47                low = mid + 1;
48            }
49        }
50        return ans;
51    }
52};