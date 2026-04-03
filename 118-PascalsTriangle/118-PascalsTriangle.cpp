// Last updated: 4/3/2026, 2:02:31 PM
class Solution {
public:
    // From Pascal Triangle II
    vector<int> rows(int n) {
        vector<int> row(n, 1);
        long long res = 1;
        for (int i = 1; i < (n - 1); i++) {
            res *= (n - i);
            res /= i;
            row[i] = res;
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(rows(i));
        }
        return ans;
    }
};