// Last updated: 4/3/2026, 1:48:40 PM
class Solution {
public:
    using ll = long long;
    int n, m;
    vector<vector<vector<ll>>> dp;
    ll solve(int i, int j, vector<int>& nums1, vector<int>& nums2,
             int remainK) {
        if (remainK == 0)
            return 0;
        if (i == n || j == m)
            return -1e15;
        if (dp[i][j][remainK] != -2e17)
            return dp[i][j][remainK];

        ll take = (ll)nums1[i] * nums2[j] +
                  solve(i + 1, j + 1, nums1, nums2, remainK - 1);

        ll skipNums1 = solve(i + 1, j, nums1, nums2, remainK);
        ll skipNums2 = solve(i, j + 1, nums1, nums2, remainK);

        return dp[i][j][remainK] = max({take, skipNums1, skipNums2});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size();
        m = nums2.size();
        dp.assign(n, vector<vector<ll>>(m, vector<ll>(k + 1, -2e17)));
        return solve(0, 0, nums1, nums2, k);
    }
};