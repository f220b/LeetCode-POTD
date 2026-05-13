// Last updated: 13/5/2026, 7:33:19 pm
1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5        vector<int> diff(2 * limit + 2, 0);
6
7        for (int i = 0; i < n / 2; ++i) {
8            int a = min(nums[i], nums[n - 1 - i]);
9            int b = max(nums[i], nums[n - 1 - i]);
10
11            diff[2] += 2;
12            diff[a + 1] -= 1;
13            diff[a + b] -= 1;
14            diff[a + b + 1] += 1;
15            diff[b + limit + 1] += 1;
16        }
17
18        int min_ops = n;
19        int current_ops = 0;
20
21        for (int c = 2; c <= 2 * limit; ++c) {
22            current_ops += diff[c];
23            min_ops = min(min_ops, current_ops);
24        }
25
26        return min_ops;
27    }
28};