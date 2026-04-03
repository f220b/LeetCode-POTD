// Last updated: 4/3/2026, 1:49:52 PM
class Spreadsheet {
    vector<vector<int>> grid;

public:
    Spreadsheet(int rows) { grid.assign(rows, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1);
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        return getOperand(left) + getOperand(right);
    }

    int getOperand(string s) {
        if (isalpha(s[0])) {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            return grid[row][col];
        }
        return stoi(s);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */