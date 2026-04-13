// Last updated: 13/4/2026, 11:21:19 pm
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> angles;
        sort(sides.begin(), sides.end());
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c)
            return angles;

        double A = acos((b * b + c * c - a * a) / (2 * b * c));
        double B = acos((a * a + c * c - b * b) / (2 * a * c));
        double C = acos((b * b + a * a - c * c) / (2 * a * b));

        double radToDeg = 180.0 / M_PI;
        A *= radToDeg;
        B *= radToDeg;
        C *= radToDeg;

        angles = {A, B, C};
        sort(angles.begin(), angles.end());
        return angles;
    }
};