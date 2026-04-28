// Last updated: 4/28/2026, 2:52:35 PM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++)
            mpp[nums[i]].push_back(i);

        for (auto& it : mpp) {
            vector<int> pos = it.second;

            long long totalSum = 0;
            for (int p : pos)
                totalSum += (long long)p;

            long long leftSum = 0;
            long long rightSum = totalSum;
            int m = pos.size();
            for (int i = 0; i < m; i++) {
                ans[pos[i]] += ((long long)i * pos[i]) - leftSum;
                
                leftSum += (long long)pos[i];
                rightSum -= pos[i];
                
                ans[pos[i]] += rightSum - (long long)(m - i - 1) * pos[i];
            }
        }
        return ans;
    }
};