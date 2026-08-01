// Last updated: 8/1/2026, 8:50:34 PM
1#define pb push_back
2class Solution {
3public:
4    using ll = long long;
5    int maximumWidth(vector<int>& pl) {
6        unordered_map<ll, ll> freq;
7        for (int p : pl)
8            freq[p]++;
9
10        vector<ll> vals;
11        vals.reserve(freq.size());
12        for (auto& kv : freq)
13            vals.pb(kv.first);
14
15        sort(vals.begin(), vals.end());
16        int d = vals.size();
17
18        unordered_map<ll, ll> match;
19        for (int i = 0; i < d; i++) {
20            for (int j = i; j < d; j++) {
21                ll a = vals[i], b = vals[j];
22                ll h = a + b;
23                ll contri = (i == j) ? (freq[a] >> 1) : min(freq[a], freq[b]);
24                if (contri > 0)
25                    match[h] += contri;
26            }
27        }
28        ll best = 1;
29        for (auto& kv : freq) {
30            ll h = kv.first, w = kv.second;
31            auto it = match.find(h);
32            if (it != match.end())
33                w += it->second;
34            best = max(best, w);
35        }
36
37        for (auto& kv : match) {
38            ll h = kv.first, w = kv.second;
39            auto it = freq.find(h);
40            if (it != freq.end())
41                w += it->second;
42            best = max(best, w);
43        }
44        return (int)best;
45    }
46};