// Last updated: 4/3/2026, 2:01:35 PM
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prevBuy(k+1, 0);
        vector<int> prevNotBuy(k+1, 0);
        
        vector<int> currBuy(k+1, 0);
        vector<int> currNotBuy(k+1, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int cap = 1; cap <= k; cap++) {
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
        return prevBuy[k];
    }
};