// Last updated: 30/5/2026, 10:18:18 pm
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<vector<int>> characters(26, vector<int>(2, 0));
        for (char ch : word) {
            if (isupper(ch))
                characters[ch - 'A'][0] = 1;
            else if (islower(ch))
                characters[ch - 'a'][1] = 1;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (characters[i][0] && characters[i][1])
                count++;
        }
        return count;
    }
};