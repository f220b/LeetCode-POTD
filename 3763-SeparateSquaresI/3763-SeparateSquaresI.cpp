// Last updated: 4/3/2026, 1:50:07 PM
class Solution {
public:
    double belowArea(double y, vector<vector<int>>& squares) {
        double area = 0.0;
        for (auto& square : squares) {
            double y1 = square[1], l = square[2];
            if (y > y1) {
                double side = min(y - y1, l);
                area += (side * l);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double eps = 1e-6;
        double low = 0.0, high = 0.0;
        double totalArea = 0.0;
        for (auto& square : squares) {
            high = max(high, (double)square[1] + square[2]);
            totalArea += ((double)square[2] * square[2]);
        }

        for (int i = 0; i < 70; i++) {
            double mid = low + (high - low) / 2;
            double below = belowArea(mid, squares);
            double above = totalArea - below;

            if (below >= above)
                high = mid;
            else
                low = mid;
        }
        return (low + high) / 2.0;
    }
};
