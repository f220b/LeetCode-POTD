// Last updated: 9/5/2026, 12:16:02 AM
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