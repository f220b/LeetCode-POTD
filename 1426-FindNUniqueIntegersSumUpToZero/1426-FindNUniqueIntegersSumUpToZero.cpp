// Last updated: 4/3/2026, 1:57:06 PM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if(n % 2 != 0)
            result.push_back(0);
        for(int i = 1; i <= n / 2;i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};