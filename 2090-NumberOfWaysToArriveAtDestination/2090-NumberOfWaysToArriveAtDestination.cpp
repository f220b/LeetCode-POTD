// Last updated: 4/3/2026, 1:54:49 PM
class Solution {
public:
    using p = pair<long long, int>;
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& road : roads) {
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({time[0], 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int currCity = pq.top().second;
            pq.pop();
            if (currTime > time[currCity])
                continue;

            for (auto& itr : adjList[currCity]) {
                int nextCity = itr.first;
                long long newTime = currTime + itr.second;

                if (time[nextCity] > newTime) {
                    time[nextCity] = newTime;
                    pq.push({newTime, nextCity});
                    ways[nextCity] = ways[currCity];
                } else if (time[nextCity] == newTime) {
                    ways[nextCity] = (ways[nextCity] + ways[currCity]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};