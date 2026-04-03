// Last updated: 4/3/2026, 2:02:20 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            auto [curr, len] = q.front();
            q.pop();

            if (curr == endWord)
                return len;

            for (int i = 0; i < curr.length(); i++) {
                string temp = curr;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.count(temp)) {
                        q.push({temp, len + 1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};