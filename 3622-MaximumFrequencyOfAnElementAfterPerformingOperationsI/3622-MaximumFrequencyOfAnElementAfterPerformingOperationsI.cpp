// Last updated: 4/3/2026, 1:50:47 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        vector<int> freq(maxVal + 1, 0);

        for (int num : nums)
            freq[num]++;
        for (int i = 1; i <= maxVal; i++)
            freq[i] += freq[i - 1];

        int result = 0;
        for (int i = 0; i <= maxVal; i++) {
            int l = max(i - k, 0);
            int r = min(i + k, maxVal);
            int rangeCount = freq[r] - (l > 0 ? freq[l - 1] : 0);
            int targetCount = freq[i] - (i > 0 ? freq[i - 1] : 0);
            int reqOperations = rangeCount - targetCount;
            
            result = max(result, targetCount + min(reqOperations, numOperations));
        }
        return result;
    }
};
