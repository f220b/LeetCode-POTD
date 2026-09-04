// Last updated: 9/5/2026, 12:00:38 AM
#define pb push_back
class Solution {
public:
    using ll = long long;
    int maximumWidth(vector<int>& pl) {
        unordered_map<ll, ll> freq;
        for (int p : pl)
            freq[p]++;

        vector<ll> vals;
        vals.reserve(freq.size());
        for (auto& kv : freq)
            vals.pb(kv.first);

        sort(vals.begin(), vals.end());
        int d = vals.size();

        unordered_map<ll, ll> match;
        for (int i = 0; i < d; i++) {
            for (int j = i; j < d; j++) {
                ll a = vals[i], b = vals[j];
                ll h = a + b;
                ll contri = (i == j) ? (freq[a] >> 1) : min(freq[a], freq[b]);
                if (contri > 0)
                    match[h] += contri;
            }
        }
        ll best = 1;
        for (auto& kv : freq) {
            ll h = kv.first, w = kv.second;
            auto it = match.find(h);
            if (it != match.end())
                w += it->second;
            best = max(best, w);
        }

        for (auto& kv : match) {
            ll h = kv.first, w = kv.second;
            auto it = freq.find(h);
            if (it != freq.end())
                w += it->second;
            best = max(best, w);
        }
        return (int)best;
    }
};