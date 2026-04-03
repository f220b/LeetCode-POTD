// Last updated: 4/3/2026, 1:54:36 PM
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> bestSingle(n, 0);
        bestSingle[0] = events[0][2];

        for (int i = 1; i < n; i++) {
            bestSingle[i] = max(bestSingle[i - 1], events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]);

            int l = 0, r = i - 1, prev = -1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (events[m][1] < events[i][0]) {
                    prev = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (prev != -1)
                ans = max(ans, events[i][2] + bestSingle[prev]);
        }

        return ans;
    }
};
