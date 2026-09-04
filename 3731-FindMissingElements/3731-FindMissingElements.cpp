// Last updated: 9/5/2026, 12:05:20 AM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int minE = 1e9, maxE = -1e9;
        for (int n : nums) {
            minE = min(minE, n);
            maxE = max(maxE, n);
        }
        sort(nums.begin(), nums.end());
        for (int i = minE; i <= maxE; i++) {
            if (!binary_search(nums.begin(), nums.end(), i))
                ans.push_back(i);
        }
        return ans;
    }
};