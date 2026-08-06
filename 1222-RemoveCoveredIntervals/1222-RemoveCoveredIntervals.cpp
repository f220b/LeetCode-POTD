// Last updated: 8/6/2026, 1:18:14 PM
class Solution {
public:
    using vi = vector<int>;
    static bool compare(vi& a, vi& b) {
        if (a[0] < b[0])
            return true;
        if (a[0] == b[0] && a[1] >= b[1])
            return true;
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        vector<int> curr = intervals[0];
        vector<int> temp;
        int remove = 0;
        for (int i = 1; i < n; i++) {
            temp = intervals[i];
            if (temp[0] >= curr[0] && temp[1] <= curr[1])
                remove++;
            else
                curr = temp;
        }
        return n - remove;
    }
};