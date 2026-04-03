// Last updated: 4/3/2026, 1:49:21 PM
class Solution {
public:
    long long solve(const vector<int>& value, const vector<int>& limit,
                    vector<int>& idx) {
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (limit[a] != limit[b])
                return limit[a] < limit[b];
            return value[a] > value[b];
        });
        multiset<int> activeLimits;
        long long total = 0;
        int dead = 0;
        for (int id : idx) {
            int lim = limit[id];
            if (lim <= dead)
                continue;
            int currActive = activeLimits.size();
            if (currActive < lim) {
                total += (long long)value[id];
                int prev = currActive;
                activeLimits.insert(lim);
                int x = prev + 1;
                if (x > dead)
                    dead = x;
                auto it = activeLimits.begin();
                while (it != activeLimits.end() && *it <= x)
                    it = activeLimits.erase(it);
            }
        }
        return total;
    }
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();

        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; i++)
            pairs.emplace_back(value[i], limit[i]);

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        return solve(value, limit, idx);
    }
};