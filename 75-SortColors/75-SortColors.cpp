// Last updated: 4/3/2026, 2:03:20 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0, ones = 0, twos = nums.size() - 1;
        while (ones <= twos) {
            if (nums[ones] == 0) {
                swap(nums[zeroes], nums[ones]);
                zeroes++;
                ones++;
            } else if (nums[ones] == 1) {
                ones++;
            } else {
                swap(nums[ones], nums[twos]);
                twos--;
            }
        }
    }
};