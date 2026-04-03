// Last updated: 4/3/2026, 1:49:39 PM
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv, minOnline;
    DSU(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);
        minOnline.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            minOnline[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        minOnline[a] = min(minOnline[a], minOnline[b]);
        if (rankv[a] == rankv[b]) rankv[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections) dsu.unite(e[0], e[1]);
        
        vector<set<int>> gridOnline(c + 1);
        for (int i = 1; i <= c; i++) {
            int p = dsu.find(i);
            gridOnline[p].insert(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> ans;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int p = dsu.find(x);
            if (type == 1) {
                if (online[x]) ans.push_back(x);
                else {
                    if (gridOnline[p].empty()) ans.push_back(-1);
                    else ans.push_back(*gridOnline[p].begin());
                }
            } else {
                if (online[x]) {
                    online[x] = false;
                    gridOnline[p].erase(x);
                }
            }
        }
        return ans;
    }
};
