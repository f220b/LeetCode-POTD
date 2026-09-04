// Last updated: 9/5/2026, 12:21:39 AM
class Solution {
public:
    long long atleastKSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        long long count = 0;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            
            count += (right - left + 1);
        }
        
        return count;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        return atleastKSubarrays(nums, k);
    }
};
