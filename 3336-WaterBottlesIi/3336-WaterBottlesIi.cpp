// Last updated: 4/3/2026, 1:51:42 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles, empty = 0, total = 0;

        while(full != 0) {
            empty += full;
            total += full;
            full = 0;

            while(empty >= numExchange) {
                empty -= numExchange;
                numExchange++;
                full++;
            }
        }
        return total;
    }
};