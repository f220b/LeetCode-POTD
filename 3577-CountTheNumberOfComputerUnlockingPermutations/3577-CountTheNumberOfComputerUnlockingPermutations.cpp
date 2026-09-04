// Last updated: 9/5/2026, 12:08:28 AM
class Solution {
public:
    static const long long MOD = 1000000007LL;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        // check strict global minimum at index 0
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0])
                return 0;
        }
        // compute (n-1)! % MOD
        long long ans = 1;
        for (int i = 1; i <= n - 1; ++i)
            ans = (ans * i) % MOD;
        return (int)ans;
    }
};
