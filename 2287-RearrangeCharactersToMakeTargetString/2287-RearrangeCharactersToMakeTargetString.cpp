// Last updated: 9/5/2026, 12:21:53 AM
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> req;
        for (char ch : target)
            req[ch]++;

        unordered_map<char, int> curr;
        for (char ch : s) {
            if (req.count(ch))
                curr[ch]++;
        }
        if (curr.size() != req.size())
            return 0;
        int cnt = INT_MAX;
        for (auto itr : curr) {
            char ch = itr.first;
            cnt = min(cnt, curr[ch] / req[ch]);
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};