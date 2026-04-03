// Last updated: 4/3/2026, 1:49:51 PM
class Solution {
public:
    void sortAllVectors(vector<vector<int>>& v) {
        int N = v.size();
        for (int i = 0; i < N; i++) {
            if (v[i].size() > 1) {
                sort(v[i].begin(), v[i].end());
            }
        }
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> row(n + 1);
        vector<vector<int>> col(n + 1);
        int m = buildings.size();
        for (int i = 0; i < m; i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            row[x].push_back(y);
            col[y].push_back(x);
        }
        sortAllVectors(row);
        sortAllVectors(col);
        int count = 0;
        for (int i = 0; i < m; i++) {

            int x = buildings[i][0];
            int y = buildings[i][1];

            vector<int>& ys = row[x];
            vector<int>& xs = col[y];

            int posY = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            int posX = lower_bound(xs.begin(), xs.end(), x) - xs.begin();

            bool left = posY > 0;
            bool right = posY + 1 < (int)ys.size();
            bool above = posX > 0;
            bool below = posX + 1 < (int)xs.size();

            if (left && right && above && below)
                count++;
        }

        return count;
    }
};
