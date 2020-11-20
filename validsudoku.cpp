// #include <bit>
class Solution {
public:
    bool checkRowsandCols(vector<vector<char>>& board) {
        int rows = 9;

        int correct = (1 << 10) - 1;
        for (int i = 0; i < rows; i++) {
            int rowbits = 0;
            int colbits = 0;
            int rowcount = 0;
            int colcount = 0;
            for (int j = 0; j < rows; j++) {
               char cur_row_val = board[i][j] - 48;
               char cur_col_val = board[j][i] - 48;
               if (cur_row_val > 0) {
                 rowbits |= 1 << cur_row_val;
                 rowcount++;
               }
               if (cur_col_val > 0) {
                 colbits |= 1 << cur_col_val;
                 colcount++;
               }
            }
            if ((__builtin_popcount(rowbits) != rowcount) ||
(__builtin_popcount(colbits) != colcount)) {
                return false;
            }
        }
        return true;
    }
    
    bool checkCells(vector<vector<char>>& board) {
        int rows = 3;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
              int cellbits = 0;
              int cellcount = 0;
              for (int ii = i*3; ii < i*3 + 3; ii++) {
                  for (int jj = j*3; jj < j*3 + 3; jj++) {
                    int cur_cell_val = board[ii][jj] - 48;
                    if (cur_cell_val > 0) {
                       cellbits |= 1 << cur_cell_val;
                       cellcount++;
                    }
                 }
              }
              if (__builtin_popcount(cellbits) != cellcount) {
                  return false;
              }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRowsandCols(board) && checkCells(board);
    }
};
