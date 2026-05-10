// Last updated: 10/5/2026, 10:18:29 am
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.insert(ans.end(), nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--)
            ans.push_back(nums[i]);

        return ans;
    }
};