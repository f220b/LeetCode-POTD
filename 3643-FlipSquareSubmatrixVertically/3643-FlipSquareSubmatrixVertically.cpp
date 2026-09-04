// Last updated: 9/5/2026, 12:07:03 AM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> finalGrid = grid;
        int top = x, bottom = x + k - 1, left = y, right = y + k - 1;

        while(top <= bottom) {
            for(int j = left; j <= right; j++) 
                swap(finalGrid[top][j], finalGrid[bottom][j]);
            
            top++;
            bottom--;
        }
        return finalGrid;
    }
};