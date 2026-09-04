// Last updated: 9/5/2026, 12:05:32 AM
class Solution {
public:
    using vvi = vector<vector<int>>;
    using vi = vector<int>;
    using ll = long long;
    vvi adjList;

    ll dfs(int node, vi& baseTime) {
        if (adjList[node].empty())
            return baseTime[node];

        ll earliest = LLONG_MAX, latest = LLONG_MIN;
        for (int child : adjList[node]) {
            ll childTime = dfs(child, baseTime);
            earliest = min(earliest, childTime);
            latest = max(latest, childTime);
        }
        ll ownDuration = (latest - earliest) + baseTime[node];
        return latest + ownDuration;
    }
    ll finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        adjList.resize(n);
        for (vi edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
        }
        return dfs(0, baseTime);
    }
};