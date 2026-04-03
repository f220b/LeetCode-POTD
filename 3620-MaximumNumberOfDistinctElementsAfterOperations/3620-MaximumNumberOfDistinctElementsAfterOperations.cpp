// Last updated: 4/3/2026, 1:50:49 PM
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
