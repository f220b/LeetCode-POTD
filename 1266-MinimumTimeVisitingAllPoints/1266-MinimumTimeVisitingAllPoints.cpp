// Last updated: 9/5/2026, 12:32:58 AM
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            time += max(dx, dy);
        }
        return time;
    }
};
