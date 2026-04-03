// Last updated: 4/3/2026, 1:54:14 PM
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
