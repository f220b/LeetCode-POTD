// Last updated: 10/5/2026, 8:29:41 am
1class Solution {
2public:
3    long long minArraySum(vector<int>& nums) {
4        int maxEle = 0;
5        for (int num : nums)
6            maxEle = max(maxEle, num);
7
8        vector<bool> present(maxEle + 1, false);
9        for (int num : nums)
10            present[num] = true;
11
12        vector<int> minDiv(maxEle + 1);
13        for (int i = 0; i <= maxEle; i++)
14            minDiv[i] = i;
15
16        for (int i = 1; i <= maxEle; i++) {
17            if (present[i]) {
18                for (int j = i; j <= maxEle; j += i) {
19                    if (minDiv[j] == j)
20                        minDiv[j] = i;
21                }
22            }
23        }
24        long long sum = 0;
25        for (int num : nums)
26            sum += (long long)minDiv[num];
27
28        return sum;
29    }
30};