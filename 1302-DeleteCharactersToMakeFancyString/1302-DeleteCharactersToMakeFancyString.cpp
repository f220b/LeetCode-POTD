// Last updated: 4/3/2026, 1:57:35 PM
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