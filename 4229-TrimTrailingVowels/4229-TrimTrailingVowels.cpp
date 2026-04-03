// Last updated: 4/3/2026, 1:48:27 PM
class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.length(), idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
                s[i] != 'u') {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};