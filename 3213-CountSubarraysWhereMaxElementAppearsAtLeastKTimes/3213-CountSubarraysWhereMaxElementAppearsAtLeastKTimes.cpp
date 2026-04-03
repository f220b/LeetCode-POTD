// Last updated: 4/3/2026, 1:52:12 PM
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