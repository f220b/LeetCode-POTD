// Last updated: 23/5/2026, 5:16:04 pm
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int count = 0, n = nums.size();
5        for (int i = 0; i < n; i++) {
6            if (nums[i] > nums[(i + 1) % n])
7                count++;
8        }
9        return count <= 1;
10    }
11};