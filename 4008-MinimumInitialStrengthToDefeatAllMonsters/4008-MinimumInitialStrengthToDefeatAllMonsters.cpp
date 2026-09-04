// Last updated: 9/5/2026, 12:00:33 AM
class Solution {
public:
    using ll = long long;
    using vi = vector<int>;
    using vl = vector<ll>;
    ll minInitialStrength(vi& mon, vector<vi>& boosts) {
        int n = mon.size();
        vl diff(n + 1, 0);
        for (auto& b : boosts) {
            int l = b[0], r = b[1];
            ll v = b[2];
            diff[l] += v;
            diff[r + 1] -= v;
        }
        vl bonus(n);
        ll run = 0;
        for (int i = 0; i < n; i++) {
            run += diff[i];
            bonus[i] = run;
        }
        auto fease = [&](ll s) -> bool {
            ll curr = s;
            for (int i = 0; i < n; i++) {
                if (curr + bonus[i] < (ll)mon[i])
                    return false;
                curr -= mon[i];
                curr = (curr < 0) ? 0 : curr;
            }
            return true;
        };
        ll l = 0, h = 0;
        for (int i = 0; i < n; i++)
            h += mon[i];
        while (l < h) {
            ll mid = l + ((h - l) >> 1);
            if (fease(mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};