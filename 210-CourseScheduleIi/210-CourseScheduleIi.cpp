// Last updated: 4/3/2026, 2:01:21 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (auto itr : prerequisites) {
            adj[itr[1]].push_back(itr[0]);
            inDegree[itr[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (auto itr : adj[course]) {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                    q.push(itr);
            }
        }
        if (order.size() != n)
            return {};
        return order;
    }
};