// Last updated: 4/3/2026, 1:52:05 PM
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        const long long inf = 1e15;
        vector<vector<long long>> dist(26, vector<long long>(26, inf));
        // x to x will cost nothing
        for(int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // original[idx] to changed[idx] will cost cost[idx]
        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        // Precompute the minimum cost of x to y
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] < inf && dist[k][j] < inf)
                        dist[i][j] = min(dist[i][j], (long long)dist[i][k] + dist[k][j]);
                }
            }
        }
        long long total = 0;
        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i])
                continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(dist[u][v] >= inf)
                return -1;

            total += dist[u][v];
        }
        return total;
    }
};