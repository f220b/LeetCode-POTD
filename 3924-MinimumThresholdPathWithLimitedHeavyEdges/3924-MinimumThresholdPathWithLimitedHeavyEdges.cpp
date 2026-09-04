// Last updated: 9/5/2026, 12:05:24 AM
class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {
        vector<vector<pair<int, int>>> adj(n);
        int maxWeight = 0;
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
            maxWeight = max(maxWeight, edge[2]);
        }

        int low = 0, high = maxWeight;
        int ans = -1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            vector<int> dist(n, 1e9);
            deque<int> dq;

            dist[source] = 0;
            dq.push_back(source);
            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();

                if (u == target && dist[u] <= k)
                    break;

                for (auto edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    int cost = (w > mid) ? 1 : 0;

                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        if (cost == 0)
                            dq.push_front(v);
                        else
                            dq.push_back(v);
                    }
                }
            }
            if (dist[target] <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};