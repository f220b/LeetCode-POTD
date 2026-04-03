// Last updated: 4/3/2026, 1:53:15 PM
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int n = nums.size();
        int lastMin = -1, lastMax = -1, badIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                badIndex = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            int validStart = min(lastMin, lastMax);
            if (validStart > badIndex) {
                count += validStart - badIndex;
            }
        }
        return count;
    }
};
