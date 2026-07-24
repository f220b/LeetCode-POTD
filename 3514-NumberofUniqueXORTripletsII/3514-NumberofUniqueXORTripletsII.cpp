// Last updated: 7/24/2026, 4:09:05 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        const int max_xor = 2048;
5
6        vector<bool> pair_xor(max_xor, false);
7        vector<bool> triplet_xor(max_xor, false);
8
9        int n = nums.size();
10
11        for (int i = 0; i < n; i++) {
12            for (int j = i; j < n; j++)
13                pair_xor[nums[i] ^ nums[j]] = true;
14        }
15
16        for (int x = 0; x < max_xor; x++) {
17            if (!pair_xor[x])
18                continue;
19            for (int v : nums)
20                triplet_xor[x ^ v] = true;
21        }
22
23        int count = 0;
24        for (int i = 0; i < max_xor; i++) {
25            if (triplet_xor[i])
26                count++;
27        }
28
29        return count;
30    }
31};