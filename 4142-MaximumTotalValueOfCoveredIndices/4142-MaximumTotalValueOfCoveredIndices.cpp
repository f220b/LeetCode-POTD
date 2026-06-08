// Last updated: 8/6/2026, 11:42:00 pm
class Solution {
public:
    using ll = long long;
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<ll> curr(2, 0);
        vector<ll> prev(2, 0);

        if (s[0] == '1')
            prev[0] = prev[1] = nums[0];
        else
            prev[1] = nums[0];

        for (int i = 1; i < n; i++) {
            for (int shifted = 0; shifted < 2; shifted++) {
                ll currVal = shifted ? nums[i] : 0;
                if (s[i] == '0')
                    curr[shifted] = currVal + prev[0];
                else {
                    ll notMove = nums[i] + prev[0];
                    ll move = currVal + prev[1];
                    curr[shifted] = max(notMove, move);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};