// Last updated: 4/3/2026, 1:51:04 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0), ans;
        for (int x : nums) {
            if (++freq[x] == 2)
                ans.push_back(x);
        }
        return ans;
    }
};
