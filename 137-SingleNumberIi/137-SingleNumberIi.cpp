// Last updated: 4/3/2026, 2:02:09 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Sort the array to group the numbers that appear the same number of times together
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Iterate through the array in steps of 3 to find the single number
        for (int i = 1; i < n; i += 3) {
            // Check if the current number is different from the previous one in the group
            if (nums[i] != nums[i - 1])
                return nums[i - 1]; // Return the unique number if found
        }
        
        // If the single number is at the last position of the array
        return nums[n - 1];
    }
};
