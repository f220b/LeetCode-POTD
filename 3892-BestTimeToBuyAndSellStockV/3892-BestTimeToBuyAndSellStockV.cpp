// Last updated: 4/3/2026, 1:49:30 PM
class Solution {
public:
    using ll = long long;

    ll safeAdd(ll a, ll b) {
        if (a == LLONG_MIN || b == LLONG_MIN)
            return LLONG_MIN;
        return a + b;
    }

    ll maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<ll> neutral(k + 1, 0);
        vector<ll> longHold(k + 1, LLONG_MIN);
        vector<ll> shortHold(k + 1, LLONG_MIN);

        for (int i = n - 1; i >= 0; i--) {
            vector<ll> newNeutral = neutral;
            vector<ll> newLong = longHold;
            vector<ll> newShort = shortHold;
            for (int cap = 1; cap <= k; cap++) {
                // Neutral state
                ll buy = safeAdd(-prices[i], longHold[cap]);
                ll shortSell = safeAdd(prices[i], shortHold[cap]);
                ll skip = neutral[cap];
                newNeutral[cap] = max({buy, shortSell, skip});

                // Long hold state
                ll sell = safeAdd(prices[i], neutral[cap - 1]);
                ll hold = longHold[cap];
                newLong[cap] = max(sell, hold);

                // Short hold state
                ll buyBack = safeAdd(-prices[i], neutral[cap - 1]);
                hold = shortHold[cap];
                newShort[cap] = max(buyBack, hold);
            }
            neutral = newNeutral;
            longHold = newLong;
            shortHold = newShort;
        }
        return neutral[k];
    }
};
