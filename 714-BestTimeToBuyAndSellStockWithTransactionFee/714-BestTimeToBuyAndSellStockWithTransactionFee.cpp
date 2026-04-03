// Last updated: 4/3/2026, 1:59:18 PM
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int prevBuy = 0;
        int prevNotBuy = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] - fee + prevNotBuy, prevBuy);
            int currNotBuy = max(prices[i] + prevBuy, prevNotBuy);

            prevBuy = currBuy;
            prevNotBuy = currNotBuy;
        }
        return prevBuy;
    }
};