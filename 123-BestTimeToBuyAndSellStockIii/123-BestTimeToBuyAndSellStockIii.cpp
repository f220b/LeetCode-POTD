// Last updated: 4/3/2026, 2:02:24 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prevBuy(3, 0);
        vector<int> prevNotBuy(3, 0);
        
        vector<int> currBuy(3, 0);
        vector<int> currNotBuy(3, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int cap = 1; cap <= 2; cap++) {
                int buy = -prices[i] + prevNotBuy[cap];
                int notBuy = prevBuy[cap];
                currBuy[cap] = max(buy, notBuy);

                int sell = prices[i] + prevBuy[cap-1];
                int notSell = prevNotBuy[cap];
                currNotBuy[cap] = max(sell, notSell);
            }
            prevBuy = currBuy;
            prevNotBuy = currNotBuy;
        }
        return prevBuy[2];
    }
};