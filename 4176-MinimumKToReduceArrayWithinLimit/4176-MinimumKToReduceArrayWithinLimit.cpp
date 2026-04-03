// Last updated: 4/3/2026, 1:48:52 PM
class Solution {
public:
    bool check(vector<int>& nums, int k) {
        long long totalOps = 0;
        long long limit = (long long)k * k;

        for (int num : nums) {
            totalOps += (num + k - 1) / k;
            if (totalOps > limit)
                return false;
        }
        return true;
    }
    int minimumK(vector<int>& nums) {
        int low = 1, high = 1e9, ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};