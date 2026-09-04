// Last updated: 9/5/2026, 12:35:22 AM
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0;
        for(int len = 1; len <= k; len++) {
            rem = ((rem * 10) + 1) % k;
            if(rem % k == 0)
                return len;
        }
        return -1;
    }
};
