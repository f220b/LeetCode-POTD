// Last updated: 7/13/2026, 7:45:20 AM
#define pb push_back
class Solution {
public:
    using vi = vector<int>;
    vector<bool> pathExistenceQueries(int n, vi& nums, int maxDiff,
                                      vector<vi>& queries) {
        vector<int> breaks;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                continue;
            breaks.pb(i - 1);
        }

        vector<bool> ans;
        for (auto x : queries) {
            int u = x[0], v = x[1];
            auto itr1 = lower_bound(breaks.begin(), breaks.end(), u);
            auto itr2 = lower_bound(breaks.begin(), breaks.end(), v);
            if (itr1 == itr2)
                ans.pb(true);
            else
                ans.pb(false);
        }
        return ans;
    }
};