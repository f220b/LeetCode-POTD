// Last updated: 4/3/2026, 2:02:37 PM
class Solution {
    public int maxProfit(int[] prices) {
        int lsf = Integer.MAX_VALUE;
        int maxpro = 0;
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            if(maxpro < (prices[i] - lsf)){
                maxpro = prices[i] - lsf;
            }
        }
        return maxpro;
    }
}