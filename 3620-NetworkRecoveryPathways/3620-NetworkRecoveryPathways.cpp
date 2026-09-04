// Last updated: 9/5/2026, 12:07:50 AM
#define pb push_back

class Solution {
public:
    using vi = vector<int>;
    using ll = long long;
    using pli = pair<ll, int>;
    using pii = pair<int, int>;
    int n;
    vector<vector<pii>> adjList;

    bool isValid(int x, ll k, const vector<bool>& online) {
        vector<ll> dist(n, 2e18);
        priority_queue<pli, vector<pli>, greater<pli>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            if (u == n - 1)
                return d <= k;

            for (auto& edge : adjList[u]) {
                int v = edge.first;
                int cost = edge.second;

                if (cost < x)
                    continue;
                if (v != n - 1 && v != 0 && !online[v])
                    continue;

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vi>& edges, vector<bool>& online, ll k) {
        n = online.size();
        adjList.assign(n, vector<pii>());
        int low = INT_MAX, high = INT_MIN;

        for (const auto& i : edges) {
            int u = i[0], v = i[1], cost = i[2];
            adjList[u].pb({v, cost});
            low = min(low, cost);
            high = max(high, cost);
        }

        if (low > high)
            return -1;

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid, k, online)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};