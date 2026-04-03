// Last updated: 4/3/2026, 1:59:09 PM
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Step 1: Sort by end asc, start desc
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &x, vector<int> &y){
                 if (x[1] == y[1]) return x[0] > y[0];
                 return x[1] < y[1];
             });

        int a = -1;   // second last picked
        int b = -1;   // last picked
        int count = 0;

        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            // Case 1: both inside → good
            if (l <= a && l <= b) continue;

            // Case 2: only b inside → add one
            if (l > a && l <= b) {
                count += 1;
                // pick r (largest possible)
                a = b;
                b = r;
                continue;
            }

            // Case 3: none inside → add two
            count += 2;
            a = r - 1;
            b = r;
        }

        return count;
    }
};
