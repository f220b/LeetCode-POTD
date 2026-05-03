// Last updated: 3/5/2026, 8:17:59 am
1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& nums) {
4        int n = nums.size();
5        int even = 0, odd = 0;
6        vector<int> ans(n);
7
8        for (int i = n - 1; i >= 0; i--) {
9            if (nums[i] & 1) {
10                ans[i] = even;
11                odd++;
12            } else {
13                ans[i] = odd;
14                even++;
15            }
16        }
17        return ans;
18    }
19};