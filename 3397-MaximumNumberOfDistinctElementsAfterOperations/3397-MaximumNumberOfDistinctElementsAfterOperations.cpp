// Last updated: 9/5/2026, 12:12:28 AM
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long last = LLONG_MIN;
        int count = 0;
        
        for (int num : nums) {
            long long low = num - k;
            long long high = num + k;

            long long chosen = max(low, last + 1);
            if (chosen <= high) {
                count++;
                last = chosen;
            }
        }
        return count;
    }
};
