// Last updated: 4/3/2026, 1:51:20 PM
class Solution {
public:
    bool doesAliceWin(string s) {
        for(char c : s) {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                return true;
        }
        return false;
    }
};
