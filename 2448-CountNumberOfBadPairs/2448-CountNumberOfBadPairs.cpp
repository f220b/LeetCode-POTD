// Last updated: 4/3/2026, 1:53:32 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long goodPairs = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            if (freq.count(i - nums[i])) {
                goodPairs += freq[i - nums[i]];
            }
            freq[i - nums[i]]++;
        }
        long long badPairs = (n * (n - 1) / 2) - goodPairs;
        return badPairs;
    }
};