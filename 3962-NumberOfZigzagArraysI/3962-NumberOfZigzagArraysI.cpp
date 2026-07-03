// Last updated: 7/3/2026, 10:26:03 AM
class Solution {
public:
    using ll = long long;
    using vll = vector<ll>;
    const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        if (n == 1)
            return r - l + 1;

        vector<vll> prev(r + 1, vll(2, 0));
        vector<vll> curr(r + 1, vll(2, 0)); // Declared outside to prevent TLE
        
        for (int i = l; i <= r; i++) {
            prev[i][1] = 1;
            prev[i][0] = 1;
        }

        for (int len = 2; len <= n; len++) {
            // Reset curr values safely instead of re-allocating
            for (int i = l; i <= r; i++) {
                curr[i][0] = 0;
                curr[i][1] = 0;
            }
            
            ll suffix_sum = 0;
            for (int x = r - 1; x >= l; x--) {
                suffix_sum = (suffix_sum + prev[x + 1][0]) % MOD;
                curr[x][1] = suffix_sum;
            }

            ll prefix_sum = 0;
            for (int x = l + 1; x <= r; x++) {
                prefix_sum = (prefix_sum + prev[x - 1][1]) % MOD;
                curr[x][0] = prefix_sum;
            }
swap(prev, curr);
        }

        ll ans = 0;
        for (int x = l; x <= r; x++) {
            ans = (ans + prev[x][1]) % MOD;
            ans = (ans + prev[x][0]) % MOD;
        }
        return (int)ans;
    }
};