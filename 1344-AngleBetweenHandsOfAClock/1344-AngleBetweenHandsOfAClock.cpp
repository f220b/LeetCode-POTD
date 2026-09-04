// Last updated: 9/5/2026, 12:32:13 AM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (30 * hour) + (minutes / 2.0);
        double m = 6 * minutes;
        double ans = abs(h - m);
        return min(ans, 360 - ans);
    }
};