// Last updated: 4/3/2026, 2:02:25 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevBuy = 0, prevNotBuy = 0;
        int currBuy = 0, currNotBuy = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int buy = -prices[i] + prevNotBuy;
            int notBuy = prevBuy;
            currBuy = max(buy, notBuy);

            int sell = prices[i] + prevBuy;
            int notSell = prevNotBuy;
            currNotBuy = max(sell, notSell);

            prevBuy = currBuy;
            prevNotBuy = currNotBuy;

        }
        return prevBuy;
    }
};