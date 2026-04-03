// Last updated: 4/3/2026, 1:59:39 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result = mat;

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) 
                    q.push({i, j});
                else
                    result[i][j] = -1;
            }
        }
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int newI = i + di[k];
                int newJ = j + dj[k];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && result[newI][newJ] == -1) {
                    result[newI][newJ] = 1 + result[i][j];
                    q.push({newI, newJ});
                }
            }            
        }
        return result;
    }
};