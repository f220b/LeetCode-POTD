// Last updated: 9/5/2026, 12:19:31 AM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        int n = nums.size();
        int left = 0, right = 0;
        long long result = 0, total_pairs = 0;

        while (right < n) {
            total_pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (total_pairs >= k) {
                result += (n - right);
                freq[nums[left]]--;
                total_pairs -= freq[nums[left]];
                left++;
            }
            right++;
        }
        return result;
    }
};