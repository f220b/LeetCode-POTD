// Last updated: 25/4/2026, 11:30:52 pm
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            pref[i] = (nums[i] & 1) ? 0 : 1;
            if (i > 0)
                pref[i] += pref[i - 1];
        }
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0], r = query[1], k = query[2];
            long long low = 1, high = 2147483646;
            long long res = -1;

            int evensInRange = pref[r] - (l > 0 ? pref[l - 1] : 0);
            int firstEven = nums[l], lastEven = nums[r];

            while (low <= high) {
                long long mid = low + ((high - low) >> 1);
                long long val = mid;
                if (val & 1)
                    val--;

                long long totalEvensUpToMid = val >> 1;
                long long removedCount = 0;

                int subL = nums[l], subR = nums[r];
                if (val >= subL) {
                    if (val >= subR) {
                        removedCount = evensInRange;
                    } else {
                        auto it = upper_bound(nums.begin() + l,
                                              nums.begin() + r + 1, (int)val);
                        int idx = distance(nums.begin(), it) - 1;
                        removedCount = pref[idx] - (l > 0 ? pref[l - 1] : 0);
                    }
                }
                if (totalEvensUpToMid - removedCount >= k) {
                    res = val;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};