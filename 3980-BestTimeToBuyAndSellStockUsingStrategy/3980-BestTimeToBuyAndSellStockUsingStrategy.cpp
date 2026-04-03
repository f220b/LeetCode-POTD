// Last updated: 4/3/2026, 1:49:16 PM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> leftGain(n), rightGain(n);

        for (int i = 0; i < n; i++) {
            leftGain[i] = -1LL * strategy[i] * prices[i];
            rightGain[i] = (1LL - strategy[i]) * prices[i];
        }

        vector<long long> prefixLeft(n + 1, 0), prefixRight(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixLeft[i + 1] = prefixLeft[i] + leftGain[i];
            prefixRight[i + 1] = prefixRight[i] + rightGain[i];
        }
        long long baseProfit = 0;
        for (int i = 0; i < n; i++)
            baseProfit += 1LL * strategy[i] * prices[i];

        long long bestDelta = LLONG_MIN;
        int half = k / 2;
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;

            long long leftPart = prefixLeft[mid] - prefixLeft[l];
            long long rightPart = prefixRight[r] - prefixRight[mid];
            long long delta = leftPart + rightPart;
            bestDelta = max(bestDelta, delta);
        }
        return max(baseProfit, baseProfit + bestDelta);
    }
};