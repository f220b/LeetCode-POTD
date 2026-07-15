// Last updated: 7/15/2026, 12:20:06 PM
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    using vi = vector<int>;
5    int n;
6    int dp[201][201][201];
7
8    int helper(int i, int g1, int g2, vi& nums) {
9        if (i == n)
10            return (g1 != 0 && g1 == g2);
11
12        int ans = 0;
13        if (dp[i][g1][g2] != -1)
14            return dp[i][g1][g2];
15
16        ans = helper(i + 1, g1, g2, nums);
17        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
18        ans = (ans + helper(i + 1, ng1, g2, nums)) % MOD;
19
20        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
21        ans = (ans + helper(i + 1, g1, ng2, nums)) % MOD;
22
23        return dp[i][g1][g2] = ans;
24    }
25    int subsequencePairCount(vector<int>& nums) {
26        n = nums.size();
27        memset(dp, -1, sizeof(dp));
28        return helper(0, 0, 0, nums);
29    }
30};