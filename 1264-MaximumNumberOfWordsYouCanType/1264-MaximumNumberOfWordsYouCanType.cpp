// Last updated: 4/3/2026, 1:57:41 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());

        int count = 0;
        stringstream ss(text);
        string word;

        while (ss >> word) {
            bool ok = true;
            for (char c : word) {
                if (st.count(c)) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                count++;
        }
        return count;
    }
};
