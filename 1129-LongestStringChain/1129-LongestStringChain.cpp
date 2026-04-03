// Last updated: 4/3/2026, 1:57:49 PM
class Solution {
public:
    static bool cmp(string a, string b) { return a.length() < b.length(); }

    bool isPredecessor(string& a, string& b) {
        if (b.length() != a.length() + 1)
            return false;

        int i = 0, j = 0, diff = 0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j])
                i++;
            else {
                diff++;
                if (diff > 1)
                    return false;
            }
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int lastIdx = n - 1; lastIdx >= 0; lastIdx--) {
                int notTake = next[lastIdx];
                int take = 0;
                if (lastIdx == 0 || isPredecessor(words[lastIdx - 1], words[i]))
                    take = 1 + next[i + 1];
                curr[lastIdx] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};
