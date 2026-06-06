// Last updated: 6/6/2026, 8:40:53 PM
1class Solution {
2public:
3    using ll = long long;
4    bool static compare(const vector<int>& a, const vector<int>& b) {
5        return a[0] < b[0];
6    }
7    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
8        sort(intervals.begin(), intervals.end(), compare);
9        int totalTimeUnits = 0;
10        int currStart = intervals[0][0], currEnd = intervals[0][1];
11
12        for (int i = 1; i < intervals.size(); i++) {
13            if (intervals[i][0] <= currEnd + 1)
14                currEnd = max(currEnd, intervals[i][1]);
15            else {
16                totalTimeUnits += (currEnd - currStart + 1);
17                currStart = intervals[i][0];
18                currEnd = intervals[i][1];
19            }
20        }
21        totalTimeUnits += (currEnd - currStart + 1);
22        ll minBulbs = 0;
23        if (brightness == n)
24            minBulbs = (n + 2) / 3;
25        else
26            minBulbs = (brightness + 2) / 3;
27
28        return minBulbs * totalTimeUnits;
29    }
30};