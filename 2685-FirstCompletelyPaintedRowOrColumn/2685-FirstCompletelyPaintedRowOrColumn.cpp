// Last updated: 4/3/2026, 1:52:54 PM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> valueToIndex;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                valueToIndex[mat[i][j]] = make_pair(i, j);
            }
        }

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for (int i = 0; i < m * n; i++) {
            int val = arr[i];
            pair<int, int> position = valueToIndex[val];
            int row = position.first;
            int col = position.second;

            rows[row]++;
            cols[col]++;

            if (rows[row] == n || cols[col] == m) {
                return i;
            }
        }
        return -1;
    }
};
