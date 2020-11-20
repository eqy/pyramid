class Solution2 {
public:
    int placeValidDigit(vector<vector<char>>& board, vector<vector<char>>&
newboard, int digit) {
      int dim = 9;
      for (int i = 0; i < dim; i++) {
          for (int j = 0; j < dim; j++) {
              if (board[i][j] == '.') {
                  int cell_i = i/3;
                  int cell_j = j/3;
                  for (int idx = 0; idx < dim; idx++) {
                    if (board[i][idx] - 48 == digit || board[idx][j] - 48 ==
digit) {
                        return 0;
                    }
                  }
                  for (int ii=cell_i * 3; ii < (cell_i+1)*3; ii++) {
                      for (int jj=cell_j * 3; jj < (cell_j+1)*3; jj++) {
                          if (board[ii][jj] - 48 == digit) {
                              return 0;
                          }
                      }
                  }
                  newboard[i][j] = (char) (digit + 48);
                  return 1;
              }
          }
      }
      return -1;
    }
    
    int _solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> newboard;
        for (int i = 1; i < 10; i++) {
              newboard = board;
              int res = placeValidDigit(board, newboard, i);
              if (res < 0) {
                board = newboard;
                return 1;
              } else if (res > 0) {
                if (_solveSudoku(newboard)) {
                    board = newboard;
                    return 1;
                }
              }
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> newboard = board;
        _solveSudoku(board);
    }
};

class Solution {
public:
    int validDigits(vector<vector<char>>& board, int& bitmask, int& i, int& j) {
        int dim = 9;
        bitmask = 0;
        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                if (board[i][j] == '.') {
                  for (int idx = 0; idx < dim; idx++) {
                      int row_val = board[i][idx] - 48;
                      int col_val = board[idx][j] - 48;
                      if (row_val > 0) {
                        bitmask |= 1 << row_val;
                      }
                      if (col_val > 0) {
                        bitmask |= 1 << col_val;
                      }
                  }
                  int cell_i = i/3;
                  int cell_j = j/3;
                  for (int ii=cell_i*3; ii < cell_i*3 + 3; ii++) {
                      for (int jj=cell_j*3; jj < cell_j*3 +3; jj++) {
                          int cell_val = board[ii][jj] - 48;
                          if (cell_val > 0) {
                            bitmask |= 1 << cell_val;
                          }
                      }
                  }
                  return 0;
                }
            }
        }
        return 1;
    }
    
    int _solveSudoku(vector<vector<char>>& board) {
        int bitmask;
        int full = (1 << 10) - 1;
        int i;
        int j;
        int res = validDigits(board, bitmask, i, j);
     
        if (res) {
            return res;
        } else {
            if (bitmask ^ full) {                
                for (int d = 1; d < 10; d++) {
                    if (bitmask == full) {
                        break;
                    }
                    if (bitmask & (1 << d)) {
                        continue;
                    }
                    bitmask |= 1 << d;
                    board[i][j] = (char) (d + 48);
                    if (_solveSudoku(board)) {
                        return 1;
                    }
                }
                board[i][j] = '.';
                return 0;
            } else {
                return 0;
            }
        }
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        _solveSudoku(board);
    }
};
