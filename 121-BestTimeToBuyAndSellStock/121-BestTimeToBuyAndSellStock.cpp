// Last updated: 4/3/2026, 2:02:29 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = prices[0], maxPro = 0;
        for(int i = 1; i < prices.size(); i++) {
            int curr = prices[i];
            maxPro = max(maxPro, curr-best);
            best = min(prices[i], best);
        }
        return maxPro;
    }
};