// Last updated: 4/3/2026, 1:54:54 PM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.length(); i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1)
                first[ch] = i;
            last[ch] = i;
        }
        int count = 0;
        for (int ch = 0; ch < 26; ch++) {
            if (first[ch] != -1 && last[ch] - first[ch] > 1) {
                unordered_set<char> st;
                for (int j = first[ch] + 1; j < last[ch]; j++)
                    st.insert(s[j]);
                count += st.size();
            }
        }
        return count;
    }
};