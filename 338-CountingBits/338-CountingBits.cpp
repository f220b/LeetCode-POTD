// Last updated: 4/3/2026, 2:00:30 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            if((n >> i) & 1)
                count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        for(int i = 0; i <= n; i++) {
            result[i] = hammingWeight(i);
        }
        return result;
    }
};