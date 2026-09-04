// Last updated: 9/5/2026, 12:33:59 AM
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
