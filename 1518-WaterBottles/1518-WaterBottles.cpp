// Last updated: 9/5/2026, 12:29:51 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles, empty = 0;
        int total = 0;

        while(full != 0) {
            total += full;
            empty += full;
            full = 0;
            if(empty >= numExchange) {
                full = empty / numExchange;
                empty = empty % numExchange;
            }
        }
        return total;
    }
};