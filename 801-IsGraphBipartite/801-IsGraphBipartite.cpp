// Last updated: 4/3/2026, 1:58:51 PM
class Solution {
public:
    vector<int> colors;
    bool dfs(int i, int color, vector<vector<int>>& graph) {
        colors[i] = color;

        for (auto node : graph[i]) {
            if (colors[node] == color)
                return false;
            if (colors[node] == -1) {
                int nextColor = color == 1 ? 0 : 1;
                if (!dfs(node, nextColor, graph))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1)
                if (!dfs(i, 1, graph))
                    return false;
        }
        return true;
    }
};