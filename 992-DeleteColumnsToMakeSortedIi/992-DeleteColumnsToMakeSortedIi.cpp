// Last updated: 4/3/2026, 1:58:16 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        int deletion = 0;
        vector<bool> alreadySorted(rows-1, false);
        for(int col = 0; col < cols; col++) {
            bool bad = false;
            for(int row = 0; row < rows-1; row++) {
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]) {
                    deletion++;
                    bad = true;
                    break;
                }
            }
            if(bad)
                continue;
            for(int row = 0; row < rows-1; row++) {
                if(strs[row][col] < strs[row+1][col])
                    alreadySorted[row] = true;
            }
        }
        return deletion;
    }
};