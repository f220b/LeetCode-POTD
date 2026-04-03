// Last updated: 4/3/2026, 1:57:02 PM
class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '6') {
                str[i] = '9';
                break;
            }
        }
        return stoi(str);
    }
};