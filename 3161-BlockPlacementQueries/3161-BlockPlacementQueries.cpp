// Last updated: 9/5/2026, 12:14:27 AM
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) max_x = max(max_x, q[1]);
        
        n = max_x + 1;
        tree.assign(4 * n, 0);
        set<int> obstacles;
        obstacles.insert(0);
        update(1, 0, n - 1, 0, 0);

        vector<bool> results;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.lower_bound(x);
                int prev = *(--it);
                obstacles.insert(x);
                update(1, 0, n - 1, x, x - prev);
                auto next_it = obstacles.upper_bound(x);
                if (next_it != obstacles.end()) {
                    update(1, 0, n - 1, *next_it, *next_it - x);
                }
            } else {
                int x = q[1], sz = q[2];
                auto it = obstacles.upper_bound(x);
                int last_obs = *(--it);
                int max_gap = max(query(1, 0, n - 1, 0, last_obs), x - last_obs);
                results.push_back(max_gap >= sz);
            }
        }
        return results;
    }
};