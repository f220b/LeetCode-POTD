// Last updated: 7/3/2026, 10:25:14 AM
class Solution {
public:
    using vi = vector<int>;
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vi prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + (nums[i] == target);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                int cnt = prefixSum[j + 1] - prefixSum[i];
                if (2 * cnt > len)
                    ans++;
            }
        }
        return ans;
    }
};