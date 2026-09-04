// Last updated: 9/5/2026, 12:04:15 AM
#define sz(x) (int)(x).size()

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    using vi = vector<int>;

    ll solve(vi& nums, int k) {
        ll sum = -2e18, curr = 0;

        for (int x : nums) {
            int val = (x % k) ? -x : x;
            curr += (int)val;
            sum = max(sum, curr);
            if (curr < 0)
                curr = 0;
        }
        return sum;
    }
    int divisibleGame(vector<int>& nums) {
        int n = sz(nums);
        set<int> cd;
        cd.insert(2);

        for (int x : nums) {
            for (int i = 1; i * i <= x; i++) {
                if (x % i)
                    continue;
                if (i > 1)
                    cd.insert(i);
                if ((x / i) > 1)
                    cd.insert(x / i);
            }
        }

        ll bestDiff = -2e18;
        int bestK = -1;

        for (auto x : cd) {
            ll currDiff = solve(nums, x);
            if (currDiff > bestDiff) {
                bestDiff = currDiff;
                bestK = x;
            }
        }
        return (((bestDiff % MOD + MOD) % MOD) * (bestK % MOD)) % MOD;
    }
};