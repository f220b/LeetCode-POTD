// Last updated: 4/28/2026, 2:52:54 PM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        int n = queries[0].length();

        for (const string& q : queries) {
            for (const string& d : dictionary) {
                int diff = 0;
                for (int i = 0; i < n; ++i) {
                    if (q[i] != d[i]) {
                        diff++;
                    }
                    if (diff > 2) break;
                }
                if (diff <= 2) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};