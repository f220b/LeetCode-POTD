// Last updated: 4/3/2026, 1:53:33 PM
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        
        auto dfs = [&](int start, vector<int>& dist) {
            int d = 0, curr = start;
            while (curr != -1 && dist[curr] == -1) {
                dist[curr] = d++;
                curr = edges[curr];
            }
        };
        
        dfs(node1, dist1);
        dfs(node2, dist2);
        
        int minDist = INT_MAX, result = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }
};
