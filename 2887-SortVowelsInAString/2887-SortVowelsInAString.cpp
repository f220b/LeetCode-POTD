// Last updated: 4/3/2026, 1:52:33 PM
class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        string t = "";
        int i = 0;
        for (char ch : s) {
            if (!isVowel(ch)) {
                t += ch;
                continue;
            }
            t += vowels[i];
            i++;
        }
        return t;
    }
};