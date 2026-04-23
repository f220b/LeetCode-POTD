// Last updated: 23/4/2026, 7:36:48 pm
1class Solution {
2public:
3    vector<long long> distance(vector<int>& nums) {
4        int n = nums.size();
5        vector<long long> ans(n, 0);
6
7        unordered_map<int, vector<int>> mpp;
8        for (int i = 0; i < n; i++)
9            mpp[nums[i]].push_back(i);
10
11        for (auto& it : mpp) {
12            vector<int> pos = it.second;
13
14            long long totalSum = 0;
15            for (int p : pos)
16                totalSum += (long long)p;
17
18            long long leftSum = 0;
19            long long rightSum = totalSum;
20            int m = pos.size();
21            for (int i = 0; i < m; i++) {
22                ans[pos[i]] += ((long long)i * pos[i]) - leftSum;
23                
24                leftSum += (long long)pos[i];
25                rightSum -= pos[i];
26                
27                ans[pos[i]] += rightSum - (long long)(m - i - 1) * pos[i];
28            }
29        }
30        return ans;
31    }
32};