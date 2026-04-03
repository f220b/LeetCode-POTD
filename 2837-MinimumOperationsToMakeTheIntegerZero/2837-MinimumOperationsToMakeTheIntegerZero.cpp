// Last updated: 4/3/2026, 1:52:38 PM
class Solution {
public:
    int setBitsCount(long long num) {
        int count = 0;
        for(int i = 0; i < 64; i++) {
            if(num & (1LL << i))
                count++;
        }
        return count;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 1; k <= 60; k++) {
            long long target = (long long)num1 - (k * (long long)num2);
            if(target < k)
                break;
            int setBits = setBitsCount(target);
            if(setBits <= k)
                return k;
        }
        return -1;
    }
};