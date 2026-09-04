// Last updated: 9/5/2026, 12:16:46 AM
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j - k + n) % n])
                    return false;
            }
        }
        return true;
    }
};