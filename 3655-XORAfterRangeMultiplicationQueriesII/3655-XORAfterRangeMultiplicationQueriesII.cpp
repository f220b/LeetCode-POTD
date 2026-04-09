// Last updated: 9/4/2026, 5:50:58 pm
1class Solution {
2public:
3    const int mod = 1e9 + 7;
4    long long power(long long base, long long exp) {
5        long long res = 1;
6        while (exp > 0) {
7            if (exp & 1)
8                res = (res * base) % mod;
9            base = (base * base) % mod;
10            exp >>= 1;
11        }
12        return res;
13    }
14
15    long long modInv(long long n) { return power(n, mod - 2); }
16
17    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
18        int n = nums.size();
19        int limit = sqrt(n);
20
21        // group queries with small k for later processing
22        unordered_map<int, vector<vector<int>>> lightK;
23
24        for (auto& q : queries) {
25            int l = q[0], r = q[1], k = q[2], v = q[3];
26            if (k >= limit) { // large k: apply brute force
27                for (int i = l; i <= r; i += k)
28                    nums[i] = (1LL * nums[i] * v) % mod;
29            } else { // small k: process later
30                lightK[k].push_back(q);
31            }
32        }
33
34        for (auto& [k, query] : lightK) {
35            // process small queries grouped by step size k
36            vector<long long> diff(n, 1);
37            for (auto& q : query) {
38                int l = q[0], r = q[1], v = q[3];
39                // multiply starting position
40                diff[l] = (diff[l] * v) % mod;
41                // cancel the multiplication using modular inverse
42                int steps = (r - l) / k;
43                int next = l + (steps + 1) * k;
44                if (next < n) {
45                    diff[next] = (diff[next] * modInv(v)) % mod;
46                }
47            }
48
49            // propagate the multipliers with a step size of k
50            for (int i = 0; i < n; i++) {
51                if (i >= k)
52                    diff[i] = (diff[i] * diff[i - k]) % mod;
53                nums[i] = (1LL * nums[i] * diff[i]) % mod;
54            }
55        }
56
57        int ans = 0;
58        for (auto& num : nums)
59            ans ^= num;
60
61        return ans;
62    }
63};