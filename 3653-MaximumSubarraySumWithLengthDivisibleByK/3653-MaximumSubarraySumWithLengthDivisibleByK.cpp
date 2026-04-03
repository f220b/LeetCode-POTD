// Last updated: 4/3/2026, 1:50:30 PM
using ll = long long;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {
        ll subMax = LLONG_MIN, currSum = 0;
        vector<ll> minPrefixSum(k, LLONG_MAX / 2);
        minPrefixSum[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int rem = (i + 1) % k;
            subMax = max(subMax, currSum - minPrefixSum[rem]);
            minPrefixSum[rem] = min(minPrefixSum[rem], currSum);
        }
        return subMax == LLONG_MIN ? 0 : subMax;
    }
};
