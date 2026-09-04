// Last updated: 9/5/2026, 12:13:19 AM
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
