// Last updated: 9/5/2026, 12:33:39 AM
class Solution {
public:
    string makeFancyString(string s) {
        string str = "";
        for(char ch : s) {
            if(str.length() < 2 || !(ch == str[str.length() - 1] && ch == str[str.length() - 2])) {
                str += ch;
            }
        }
        return str;
    }
};