// Last updated: 4/3/2026, 1:59:17 PM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;        
        while (i < n - 1)
            i += bits[i] + 1;

        return i == n - 1;
    }
};
