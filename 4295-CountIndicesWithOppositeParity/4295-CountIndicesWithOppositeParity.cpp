// Last updated: 3/5/2026, 10:13:10 pm
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] & 1) {
                ans[i] = even;
                odd++;
            } else {
                ans[i] = odd;
                even++;
            }
        }
        return ans;
    }
};