// Last updated: 9/5/2026, 12:03:10 AM
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