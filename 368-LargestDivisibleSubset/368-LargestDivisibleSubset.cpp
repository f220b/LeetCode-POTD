// Last updated: 4/3/2026, 2:00:25 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> hashMap(n);
        for (int i = 0; i < n; i++)
            hashMap[i] = i;

        vector<int> dp(n, 1);
        int maxIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hashMap[i] = prev;
                }
            }
            if (dp[i] > dp[maxIdx])
                maxIdx = i;
        }
        vector<int> ans;
        ans.push_back(nums[maxIdx]);
        while (hashMap[maxIdx] != maxIdx) {
            ans.push_back(nums[hashMap[maxIdx]]);
            maxIdx = hashMap[maxIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
