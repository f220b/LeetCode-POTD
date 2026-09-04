// Last updated: 9/5/2026, 12:16:52 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, count = 0;
        long long ans = 0;
        int maxElement = *max_element(nums.begin(), nums.end());

        while (right < n) {
            if (nums[right] == maxElement) {
                count++;
            }
            while (left <= right && count >= k) {
                ans += (n - right);
                if (nums[left] == maxElement) {
                    count--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};