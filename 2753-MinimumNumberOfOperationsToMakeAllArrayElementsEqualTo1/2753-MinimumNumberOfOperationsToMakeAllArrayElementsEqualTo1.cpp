// Last updated: 4/3/2026, 1:52:45 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int overall_gcd = nums[0];
        for (int x : nums) overall_gcd = gcd(overall_gcd, x);
        if (overall_gcd != 1) return -1;

        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;

        int min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int curr_gcd = nums[i];
            for (int j = i; j < n; j++) {
                curr_gcd = gcd(curr_gcd, nums[j]);
                if (curr_gcd == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return (min_len - 1) + (n - 1);
    }
};
