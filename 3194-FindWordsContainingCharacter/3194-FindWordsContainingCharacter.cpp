// Last updated: 4/3/2026, 1:52:15 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            for (char ch : str) {
                if (ch == x) {
                    indices.push_back(i);
                    break;
                }
            }
        }
        return indices;
    }
};