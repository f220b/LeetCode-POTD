// Last updated: 9/5/2026, 12:01:11 AM
class Solution {
public:
    using ll = long long;
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + (ll)nums[i];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll currSum = prefixSum[j + 1] - prefixSum[i];
                if (currSum % 10 != x)
                    continue;

                while (currSum / 10 != 0)
                    currSum /= 10;
                if (currSum == x)
                    cnt++;
            }
        }
        return cnt;
    }
};