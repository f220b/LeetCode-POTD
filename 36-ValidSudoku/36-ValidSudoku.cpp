// Last updated: 4/3/2026, 2:04:03 PM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 rows, 9 cols, 9 boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue; // skip empty

                // Find sub-box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // If already exists -> invalid
                if (rows[i].count(c) || cols[j].count(c) ||
                    boxes[boxIndex].count(c))
                    return false;

                // Mark seen
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};
