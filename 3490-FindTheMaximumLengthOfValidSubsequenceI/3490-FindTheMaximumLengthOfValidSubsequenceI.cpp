// Last updated: 4/3/2026, 1:51:14 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        for (int num : nums) {
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }

        int alternating = 1;
        int lastParity = nums[0] % 2, currentParity;
        for (int i = 1; i < nums.size(); i++) {
            currentParity = nums[i] % 2;
            if (currentParity != lastParity) {
                alternating++;
                lastParity = currentParity;
            }
        }
        return max(alternating, max(even, odd));
    }
};