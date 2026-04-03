// Last updated: 4/3/2026, 1:59:48 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        bool topToBottom = false;
        vector<int> result;

        for(int i = 0; i < n; i++) {
            int row = 0;
            int col = i;
            vector<int> temp;
            while(row < m && col < n && row >= 0 && col >= 0) {
                temp.push_back(mat[row][col]);
                row++;
                col--;
            }
            if(!topToBottom)
                reverse(temp.begin(), temp.end());
            result.insert(result.end(), temp.begin(), temp.end());
            topToBottom = !topToBottom;
        }
        for(int i = 1; i < m; i++) {
            int row = i;
            int col = n - 1;
            vector<int> temp;
            while(row < m && col < n && row >= 0 && col >= 0) {
                temp.push_back(mat[row][col]);
                row++;
                col--;
            }
            if(!topToBottom)
                reverse(temp.begin(), temp.end());
            result.insert(result.end(), temp.begin(), temp.end());
            topToBottom = !topToBottom;
        }
        return result;
    }
};