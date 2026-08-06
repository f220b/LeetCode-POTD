// Last updated: 8/6/2026, 1:06:38 PM
class Solution {
public:
    int minimumPushes(string word) {
        set<char> st;
        int pushes = 0;
        for (char ch : word) {
            pushes += (st.size() / 8) + 1;
            if (!st.count(ch))
                st.insert(ch);
        }
        return pushes;
    }
};