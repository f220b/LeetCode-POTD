// Last updated: 9/5/2026, 12:16:12 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long maxArea = 0, maxDiag = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            long long len = dimensions[i][0];
            long long bre = dimensions[i][1];
            long long diag2 = (len * len) + (bre * bre);

            if(diag2 == maxDiag) {
                maxArea = max(maxArea, len * bre);
            } else if(diag2 > maxDiag) {
                maxDiag = diag2;
                maxArea = len * bre;
            }
        }
        return (int)maxArea;
    }
};