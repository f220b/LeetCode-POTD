// Last updated: 7/9/2026, 7:58:19 AM
1#define pb push_back
2class Solution {
3public:
4    using vi = vector<int>;
5    vector<bool> pathExistenceQueries(int n, vi& nums, int maxDiff,
6                                      vector<vi>& queries) {
7        vector<int> breaks;
8        for (int i = 1; i < n; i++) {
9            if (nums[i] - nums[i - 1] <= maxDiff)
10                continue;
11            breaks.pb(i - 1);
12        }
13
14        vector<bool> ans;
15        for (auto x : queries) {
16            int u = x[0], v = x[1];
17            auto itr1 = lower_bound(breaks.begin(), breaks.end(), u);
18            auto itr2 = lower_bound(breaks.begin(), breaks.end(), v);
19            if (itr1 == itr2)
20                ans.pb(true);
21            else
22                ans.pb(false);
23        }
24        return ans;
25    }
26};