// Last updated: 7/22/2026, 11:27:45 PM
1class Solution {
2public:
3    using vi = vector<int>;
4    vi maxActiveSectionsAfterTrade(string s,
5                                            vector<vi>& queries) {
6        int n = s.length();
7        int total_ones = 0;
8        for (char c : s) {
9            if (c == '1')
10                total_ones++;
11        }
12
13        vi type;
14        vi start;
15        vi end_idx;
16
17        for (int i = 0; i < n;) {
18            int j = i;
19            while (j < n && s[j] == s[i]) 
20                j++;
21
22            type.push_back(s[i] - '0');
23            start.push_back(i);
24            end_idx.push_back(j - 1);
25            i = j;
26        }
27
28        int N = type.size();
29
30        vi pos_to_seg(n);
31        for (int i = 0; i < N; i++) {
32            for (int j = start[i]; j <= end_idx[i]; j++) 
33                pos_to_seg[j] = i;
34        }
35
36        vi ans(N, 0);
37        for (int i = 1; i < N - 1; i++) {
38            if (type[i] == 1) {
39                ans[i] = (end_idx[i - 1] - start[i - 1] + 1) +
40                         (end_idx[i + 1] - start[i + 1] + 1);
41            }
42        }
43
44        vi log_table(N + 1, 0);
45        for (int i = 2; i <= N; i++) 
46            log_table[i] = log_table[i / 2] + 1;
47
48        int K = log_table[N] + 1;
49        vector<vi> st(K, vi(N, 0));
50
51        for (int i = 0; i < N; i++) 
52            st[0][i] = ans[i];
53
54
55        for (int j = 1; j < K; j++) {
56            for (int i = 0; i + (1 << j) <= N; i++) 
57                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
58
59        }
60
61        auto queryRMQ = [&](int L_idx, int R_idx) {
62            if (L_idx > R_idx)
63                return 0;
64            int j = log_table[R_idx - L_idx + 1];
65            return max(st[j][L_idx], st[j][R_idx - (1 << j) + 1]);
66        };
67
68        auto eval = [&](int i, int L, int R, int segL, int segR) {
69            if (i <= segL || i >= segR)
70                return 0;
71            if (type[i] == 0)
72                return 0;
73
74            int left_len = 0;
75            if (i - 1 == segL)
76                left_len = max(0, end_idx[i - 1] - L + 1);
77            else
78                left_len = end_idx[i - 1] - start[i - 1] + 1;
79
80            int right_len = 0;
81            if (i + 1 == segR)
82                right_len = max(0, R - start[i + 1] + 1);
83            else
84                right_len = end_idx[i + 1] - start[i + 1] + 1;
85
86            return left_len + right_len;
87        };
88
89        vi res;
90
91        for (const auto& q : queries) {
92            int L = q[0];
93            int R = q[1];
94
95            int segL = pos_to_seg[L];
96            int segR = pos_to_seg[R];
97
98            if (segR - segL < 2) {
99                res.push_back(total_ones);
100                continue;
101            }
102
103            int max_gain = 0;
104            max_gain = max(max_gain, eval(segL + 1, L, R, segL, segR));
105            max_gain = max(max_gain, eval(segR - 1, L, R, segL, segR));
106
107            if (segL + 2 <= segR - 2)
108                max_gain = max(max_gain, queryRMQ(segL + 2, segR - 2));
109
110            res.push_back(total_ones + max_gain);
111        }
112
113        return res;
114    }
115};