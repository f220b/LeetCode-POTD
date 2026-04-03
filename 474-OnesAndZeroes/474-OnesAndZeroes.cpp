// Last updated: 4/3/2026, 1:59:54 PM
class Solution {
public:
    pair<int, int> count0And1(string& str) {
        int zero = 0, ones = 0;
        for (char ch : str) {
            if (ch == '0')
                zero++;
            else
                ones++;
        }
        return {zero, ones};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));

        for (int i = len - 1; i >= 0; i--) {
            vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));
            for (int m1 = 0; m1 <= m; m1++) {
                for (int n1 = 0; n1 <= n; n1++) {
                    int notPick = prev[m1][n1];
                    pair<int, int> itr = count0And1(strs[i]);
                    int pick = 0;
                    if (m1 - itr.first >= 0 && n1 - itr.second >= 0)
                        pick = 1 + prev[m1 - itr.first][n1 - itr.second];
                    curr[m1][n1] = max(pick, notPick);
                }
            }
            prev = curr;
        }
        return prev[m][n];
    }
};