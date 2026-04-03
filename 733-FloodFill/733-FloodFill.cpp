// Last updated: 4/3/2026, 1:59:15 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        result[sr][sc] = color;

        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int currColor = image[i][j];

            for (int k = 0; k < 4; k++) {
                int newI = i + di[k];
                int newJ = j + dj[k];
                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n &&
                    image[newI][newJ] == currColor &&
                    result[newI][newJ] == -1) {
                    q.push({newI, newJ});
                    result[newI][newJ] = color;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = (result[i][j] == -1) ? image[i][j] : result[i][j];
            }
        }
        return result;
    }
};