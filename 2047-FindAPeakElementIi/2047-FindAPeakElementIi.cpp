// Last updated: 4/3/2026, 1:54:58 PM
class Solution {
public:
    int maxElement(vector<int> arr) {
        int maxE = INT_MIN, index = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxE) {
                maxE = arr[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;

            int index = maxElement(mat[mid]);

            int top = (mid - 1 >= 0) ? mat[mid - 1][index] : INT_MIN;
            int bottom = (mid + 1 < n) ? mat[mid + 1][index] : INT_MIN;
            
            if (mat[mid][index] > top && mat[mid][index] > bottom)
                return {mid, index};
            else if (mat[mid][index] < top)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};