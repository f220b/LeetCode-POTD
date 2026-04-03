// Last updated: 4/3/2026, 1:53:00 PM
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