// Last updated: 4/3/2026, 1:54:06 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Only for cases where number of positive and negative is equal
        int pos = 0, neg = 1;
        vector<int> ans(nums.size(), 0);
        for (int i : nums) {
            if (i >= 0) {
                ans[pos] = i;
                pos += 2;
                // Positives occupy indexes 0,2,4,6.....
            } else {
                ans[neg] = i;
                neg += 2;
                // Negatives occupy indexes 1,3,5,7.....
            }
        }
        return ans;
    }
};