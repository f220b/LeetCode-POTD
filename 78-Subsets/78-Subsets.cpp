// Last updated: 4/3/2026, 2:03:11 PM
class Solution {
public:
    // Using Bit Manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Iterate through all possible subsets represented as binary numbers
        // There are 2^n subsets (2^n = 1 << n)
        for (int num = 0; num < (1 << n); num++) {
            vector<int> subs;                   // Temporary vector to store the current subset

            // Check each bit of 'num' to determine which elements to include in the subset
            for (int i = 0; i < n; i++) {
                if (num & (1 << i))             // If the ith bit is set in 'num'
                    subs.push_back(nums[i]);    // Add the ith element to the current subset
            }
            // Add the current subset to the answer
            ans.push_back(subs);
        }
        return ans;
    }
};