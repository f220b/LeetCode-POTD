// Last updated: 4/3/2026, 1:50:35 PM
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Process the first tree to find the count of nodes in each color
        // (parity)
        vector<vector<int>> adj1(n);
        for (const auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        vector<int> color1(n, -1);
        queue<int> q;
        color1[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj1[u]) {
                if (color1[v] == -1) {
                    color1[v] = color1[u] ^ 1;
                    q.push(v);
                }
            }
        }
        int count1_0 = 0, count1_1 = 0;
        for (int c : color1) {
            if (c == 0)
                count1_0++;
            else
                count1_1++;
        }

        // Process the second tree to find the count of nodes in each color
        // (parity)
        vector<vector<int>> adj2(m);
        for (const auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        vector<int> color2(m, -1);
        color2[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj2[u]) {
                if (color2[v] == -1) {
                    color2[v] = color2[u] ^ 1;
                    q.push(v);
                }
            }
        }
        int count2_0 = 0, count2_1 = 0;
        for (int c : color2) {
            if (c == 0)
                count2_0++;
            else
                count2_1++;
        }
        int max_tree2 = max(count2_0, count2_1);

        // For each node in tree1, the answer is count of same parity nodes in
        // tree1 + max_parity in tree2
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            int same_parity = (color1[i] == 0) ? count1_0 : count1_1;
            answer[i] = same_parity + max_tree2;
        }

        return answer;
    }
};