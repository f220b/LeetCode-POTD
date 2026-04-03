// Last updated: 4/3/2026, 1:58:47 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversePathList(n);
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> temp = graph[i];
            for (int& num : temp) {
                reversePathList[num].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto& itr : reversePathList[node]) {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                    q.push(itr);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};