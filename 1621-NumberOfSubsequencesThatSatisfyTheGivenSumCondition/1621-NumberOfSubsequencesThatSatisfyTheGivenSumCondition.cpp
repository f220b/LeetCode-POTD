// Last updated: 4/3/2026, 1:56:23 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1000000007;

        sort(nums.begin(), nums.end());

        /* pow2[k] = 2^k mod MOD */
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long temp = (long long)pow2[i - 1] * 2;
            pow2[i] = (int)(temp % MOD);
        }

        long long ans = 0;
        int j = n - 1;

        for (int i = 0; i < n && nums[i] * 2 <= target; i++) {
            while (i <= j && nums[i] + nums[j] > target) {
                j--;
            }
            if (i > j) break;                 // no valid max for this i
            ans += pow2[j - i];
            if (ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};

/*  Time Complexity:  O(n log n) (sorting) + O(n) scan  
    Space Complexity: O(n)  (powers of two)                         */
