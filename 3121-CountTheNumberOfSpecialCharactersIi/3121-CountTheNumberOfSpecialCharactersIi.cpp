// Last updated: 9/5/2026, 12:14:46 AM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26, -1), lower(26, -1);
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (islower(ch))
                lower[ch - 'a'] = i;
            else if (isupper(ch) && upper[ch - 'A'] == -1)
                upper[ch - 'A'] = i;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (upper[i] == -1 || lower[i] == -1)
                continue;
            if (upper[i] > lower[i])
                count++;
        }
        return count;
    }
};