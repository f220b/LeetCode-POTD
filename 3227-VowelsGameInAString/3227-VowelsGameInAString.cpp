// Last updated: 9/5/2026, 12:14:06 AM
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
