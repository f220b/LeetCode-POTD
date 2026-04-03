// Last updated: 4/3/2026, 1:52:51 PM
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0);

        for (int i = 0; i < n; i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefix[i] = 1;
            }
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        vector<int> result;
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            if (li > 0) {
                result.push_back(prefix[ri] - prefix[li - 1]);
            } else {
                result.push_back(prefix[ri]);
            }
        }
        return result;
    }
};