// Last updated: 4/3/2026, 2:00:06 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals based on their end times
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int maxNonOverlapping = 1;
        int prevEnd = intervals[0][1];

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                maxNonOverlapping++;
                prevEnd = max(prevEnd, intervals[i][1]);
            }
        }
        return intervals.size() - maxNonOverlapping;
    }
};