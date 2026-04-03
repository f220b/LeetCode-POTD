// Last updated: 4/3/2026, 1:55:18 PM
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;
        int answer = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            int colorIndex = colors[node] - 'a';
            count[node][colorIndex]++;
            answer = max(answer, count[node][colorIndex]);

            for (int neighbor : graph[node]) {
                for (int i = 0; i < 26; ++i) {
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visited == n ? answer : -1;
    }
};
