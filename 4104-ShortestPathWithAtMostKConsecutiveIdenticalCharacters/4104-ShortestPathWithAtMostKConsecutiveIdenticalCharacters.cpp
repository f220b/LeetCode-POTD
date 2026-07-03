// Last updated: 7/3/2026, 10:25:07 AM
class Solution {
public:
    using ll = long long;
    using tlii = tuple<ll, int, int>;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) 
            adj[edge[0]].push_back({edge[1], edge[2]});

        priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
        vector<vector<ll>> dist(n, vector<ll>(k + 1, 1e18));
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt])
                continue;
            if (u == n - 1)
                return d;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
                if (next_cnt <= k) {
                    if (d + w < dist[v][next_cnt]) {
                        dist[v][next_cnt] = d + w;
                        pq.push({dist[v][next_cnt], v, next_cnt});
                    }
                }
            }
        }

        return -1;
    }
};