// Last updated: 4/3/2026, 2:00:40 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevBuy = 0, prevNotBuy = 0;
        int prevBuy2 = 0, prevNotBuy2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] + prevNotBuy, prevBuy);
            int currNotBuy = max(prices[i] + prevBuy2, prevNotBuy);

            prevBuy2 = prevBuy;
            prevNotBuy = prevNotBuy2;
            prevBuy = currBuy;
            prevNotBuy = currNotBuy;
        }
        return prevBuy;
    }
};