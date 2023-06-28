class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++){
                if (board[row][column] != '.' && !isValid(board, row, column))
                    return false;
            }
        }
        return true;
    }
private:
    bool isValid(vector<vector<char>>& board, int row, int column) {
        for (int i=0; i < 9; i++) {
            if (i != row && board[row][column] == board[i][column])
                return false;
            if (i != column && board[row][column] == board[row][i])
                return false;            
        }
        
        int rowMod = row/3, colMod = column/3; 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                int rowComp = 3 * rowMod + i, colComp = 3 * colMod + j;
                if (rowComp == row && colComp == column) continue;
                if (board[rowComp][colComp] == board[row][column])
                    return false;
            }
        }
        return true;
    }
};