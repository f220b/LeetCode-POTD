// Last updated: 7/18/2026, 11:58:45 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0, n = word.length();
        string temp = "";
        unordered_set<string> st;

        for (int i = 0; i < n; i++) {
            temp.clear();
            for (int j = i; j < n; j++) {
                temp += word[j];
                st.insert(temp);
            }
        }
        for (string s : patterns) {
            if (st.find(s) != st.end())
                cnt++;
        }
        return cnt;
    }
};