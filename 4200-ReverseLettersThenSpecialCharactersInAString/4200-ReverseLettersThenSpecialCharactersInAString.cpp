// Last updated: 4/3/2026, 1:48:41 PM
class Solution {
public:
    string reverseByType(string s) {
        string special = "";
        string lower = "";
        for(char ch : s) {
            if(islower(ch))
                lower += ch;
            else if(!isalnum(ch))
                special += ch;
        }
        int idx1 = lower.length()-1, idx2 = special.length()-1;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(islower(ch)) 
                s[i] = lower[idx1--];
            else if(!isalnum(ch)) 
                s[i] = special[idx2--];
        }
        return s;
    }
};