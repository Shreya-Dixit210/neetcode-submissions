class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col) {
        char ch = board[row][col];

        // Check row
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == ch)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == ch)
                return false;
        }

        // Check 3x3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool check(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;

        int nrow = row;
        int ncol = col + 1;

        if (ncol == 9) {
            nrow++;
            ncol = 0;
        }

        // Skip empty cells
        if (board[row][col] == '.')
            return check(board, nrow, ncol);

        // Current filled cell must be valid
        if (!isSafe(board, row, col))
            return false;

        return check(board, nrow, ncol);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board, 0, 0);
    }
};
