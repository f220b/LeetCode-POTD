// Last updated: 4/3/2026, 1:56:14 PM
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