// Last updated: 4/3/2026, 1:55:54 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        vector<vector<int>> diff(rows, vector<int>(columns, 1e9));
        diff[0][0] = 0;

        using variableType = pair<int, pair<int, int>>;
        priority_queue<variableType, vector<variableType>, greater<variableType>> minHeap;
        minHeap.push({0, {0, 0}});
        int ans = INT_MAX;
        while (!minHeap.empty()) {
            auto [currDiff, pos] = minHeap.top();
            int r = pos.first, c = pos.second;
            minHeap.pop();

            if (r == rows - 1 && c == columns - 1)
                ans = min(ans, currDiff);

            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < columns) {
                    int newDiff = max(currDiff, abs(heights[nr][nc] - heights[r][c]));
                    if (newDiff < diff[nr][nc]) {
                        diff[nr][nc] = newDiff;
                        minHeap.push({newDiff, {nr, nc}});
                    }
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
