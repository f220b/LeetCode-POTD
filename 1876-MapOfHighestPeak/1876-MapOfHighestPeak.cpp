// Last updated: 4/3/2026, 1:55:34 PM
class Solution {
public:
    bool isValid(int& x, int& y, int& n, int& m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(); // Number of rows
        int m = isWater[0].size(); // Number of columns
        vector<vector<int>> height(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push(make_pair(i, j));
                    isVisited[i][j] = true;
                }
            }
        }
        int level = 0;
        vector<int> direction = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;
                for (int d = 0; d < 4; ++d) {
                    int newX = x + direction[d];
                    int newY = y + direction[d + 1];
                    if (isValid(newX, newY, n, m) && !isVisited[newX][newY]) {
                        q.push(make_pair(newX, newY));
                        height[newX][newY] = 1 + level;
                        isVisited[newX][newY] = true;
                    }
                }
            }
            level++;
        }
        return height;
    }
};
