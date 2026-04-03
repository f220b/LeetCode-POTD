// Last updated: 4/3/2026, 1:53:21 PM
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int bits = (maxVal == 0) ? 1 : 1 + log2(maxVal);

        vector<int> lastSeenSetBit(bits, n);
        vector<int> smallestSubarray(n);

        for (int i = n - 1; i >= 0; i--) {
            int nearest = i;
            for (int j = 0; j < bits; j++) {
                if ((nums[i] >> j) & 1) {
                    lastSeenSetBit[j] = i;
                } else if (lastSeenSetBit[j] != n) {
                    nearest = max(nearest, lastSeenSetBit[j]);
                }
            }
            smallestSubarray[i] = nearest - i + 1;
        }
        return smallestSubarray;
    }
};