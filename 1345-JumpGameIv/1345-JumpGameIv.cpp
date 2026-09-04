// Last updated: 9/5/2026, 12:32:11 AM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) 
            mpp[arr[i]].push_back(i);
        
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return steps;

                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    q.push(idx - 1);
                    visited[idx - 1] = 1;
                }
                if (idx + 1 < n && !visited[idx + 1]) {
                    q.push(idx + 1);
                    visited[idx + 1] = 1;
                }
                for (auto i : mpp[arr[idx]]) {
                    if (!visited[i]) {
                        q.push(i);
                        visited[i] = 1;
                    }
                }
                mpp.erase(arr[idx]);
            }
            steps++;
        }
        return -1;
    }
};