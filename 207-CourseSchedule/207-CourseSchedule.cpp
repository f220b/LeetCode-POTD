// Last updated: 4/3/2026, 2:01:23 PM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for(auto itr : prerequisites) {
            adj[itr[1]].push_back(itr[0]);
            inDegree[itr[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> result;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            result.push_back(node);

            for(int i : adj[node]) {
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }
        return result.size() == n;
    }
};