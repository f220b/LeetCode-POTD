// Last updated: 9/5/2026, 12:09:51 AM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> usedBasket(n, -1);
        int remaining = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j] && usedBasket[j] == -1) {
                    remaining--;
                    usedBasket[j] = i;
                    break;
                }
            }
        }
        return remaining;
    }
};