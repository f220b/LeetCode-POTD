// Last updated: 4/3/2026, 1:58:50 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, src}, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int stops = front.first.first;
            int city = front.first.second;
            int cost = front.second;

            if (stops > k)
                continue;

            for (auto& [nextCity, price] : adj[city]) {
                int newCost = cost + price;
                if (newCost < minCost[nextCity] && stops <= k) {
                    minCost[nextCity] = newCost;
                    q.push({{stops + 1, nextCity}, newCost});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
