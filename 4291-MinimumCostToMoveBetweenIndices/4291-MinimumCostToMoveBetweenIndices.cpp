// Last updated: 3/5/2026, 10:13:06 pm
class Solution {
public:
    using ll = long long;
    ll LeftToRight[100005];
    ll RightToLeft[100005];

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        LeftToRight[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            ll cost = 0;
            if (i == 0)
                cost = 1;
            else {
                ll next = (ll)nums[i + 1] - nums[i];
                ll prev = (ll)nums[i] - nums[i - 1];
                cost = (next < prev) ? 1 : next;
            }
            LeftToRight[i + 1] = LeftToRight[i] + cost;
        }

        RightToLeft[n - 1] = 0;
        for (int i = n - 1; i > 0; i--) {
            ll cost = 0;
            if (i == n - 1)
                cost = 1;
            else {
                ll next = (ll)nums[i + 1] - nums[i];
                ll prev = (ll)nums[i] - nums[i - 1];
                cost = (prev <= next) ? 1 : prev;
            }
            RightToLeft[i - 1] = RightToLeft[i] + cost;
        }
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0], r = query[1];
            if (l < r)
                ans.push_back((int)(LeftToRight[r] - LeftToRight[l]));
            else
                ans.push_back((int)(RightToLeft[r] - RightToLeft[l]));
        }
        return ans;
    }
};