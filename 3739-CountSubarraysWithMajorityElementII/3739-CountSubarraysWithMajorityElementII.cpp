// Last updated: 26/6/2026, 6:52:48 pm
1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        long long cnt = 0;
6
7        for (int i = 0; i < n; i++) {
8            if (nums[i] == target)
9                nums[i] = 1;
10            else
11                nums[i] = -1;
12        }
13
14        vector<int> pref(n);
15        pref[0] = nums[0];
16        for (int i = 1; i < n; i++)
17            pref[i] = pref[i - 1] + nums[i];
18
19        int shift = n;
20        vector<int> freq(2 * n + 1, 0);
21        freq[shift] = 1;
22
23        long long valid = 0;
24        int lastSum = 0;
25        for (int i = 0; i < n; i++) {
26            if (pref[i] > lastSum)
27                valid += freq[lastSum + shift];
28            else
29                valid -= freq[pref[i] + shift];
30
31            cnt += valid;
32            freq[pref[i] + shift]++;
33            lastSum = pref[i];
34        }
35        return cnt;
36    }
37};