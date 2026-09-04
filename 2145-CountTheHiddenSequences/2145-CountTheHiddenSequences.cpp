// Last updated: 9/5/2026, 12:23:11 AM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxVal = 0, minVal = 0, currVal = 0;
        for (int ele : differences) {
            currVal += ele;
            maxVal = max(maxVal, currVal);
            minVal = min(minVal, currVal);
        }
        int count = (upper - lower) - (maxVal - minVal) + 1;
        return count > 0 ? count : 0;
    }
};
