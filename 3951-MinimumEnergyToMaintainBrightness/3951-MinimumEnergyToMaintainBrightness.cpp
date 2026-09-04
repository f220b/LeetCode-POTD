// Last updated: 9/5/2026, 12:01:26 AM
class Solution {
public:
    using ll = long long;
    bool static compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int totalTimeUnits = 0;
        int currStart = intervals[0][0], currEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= currEnd + 1)
                currEnd = max(currEnd, intervals[i][1]);
            else {
                totalTimeUnits += (currEnd - currStart + 1);
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
        }
        totalTimeUnits += (currEnd - currStart + 1);
        ll minBulbs = 0;
        if (brightness == n)
            minBulbs = (n + 2) / 3;
        else
            minBulbs = (brightness + 2) / 3;

        return minBulbs * totalTimeUnits;
    }
};