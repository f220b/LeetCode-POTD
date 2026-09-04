// Last updated: 9/5/2026, 12:25:23 AM
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