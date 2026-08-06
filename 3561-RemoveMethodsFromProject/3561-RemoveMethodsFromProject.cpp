// Last updated: 8/6/2026, 1:04:58 PM
using vi = vector<int>;
#define pb push_back

class Solution {
public:
    void dfs(vi adj[], int node, vi& vis) {
        vis[node] = 1;
        for (int child : adj[node]) {
            if (!vis[child])
                dfs(adj, child, vis);
        }
    }

    vi remainingMethods(int n, int k, vector<vi>& invocations) {
        vi adj[n];
        for (auto& x : invocations)
            adj[x[0]].pb(x[1]);

        vi vis(n, 0);
        dfs(adj, k, vis);

        bool c = false;
        for (int i = 0; i < n; i++) {
            bool tmp = false;
            if (!vis[i]) {
                for (int x : adj[i]) {
                    if (vis[x]) {
                        tmp = true;
                        break;
                    }
                }
                if (tmp) {
                    c = true;
                    break;
                }
            }
        }

        vi ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                if (c)
                    ans.pb(i);
            } else {
                ans.pb(i);
            }
        }
        return ans;
    }
};