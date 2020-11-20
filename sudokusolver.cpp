class Solution {
public:
    int placeValidDigit(vector<vector<char>>& board, vector<vector<char>>&
newboard, int digit) {
      int dim = 9;
      for (int i = 0; i < dim; i++) {
          for (int j = 0; j < dim; j++) {
              if (board[i][j] == '.') {
                  int cell_i = i/3;
                  int cell_j = j/3;
                  for (int ii=cell_i * 3; ii < (cell_i+1)*3; ii++) {
                      for (int jj=cell_j * 3; jj < (cell_j+1)*3; jj++) {
                          if (board[ii][jj] - 48 == digit) {
                              return 0;
                          }
                      }
                  }
                  for (int idx = 0; idx < dim; idx++) {
                    if (board[i][idx] - 48 == digit || board[idx][j] - 48 ==
digit) {
                        return 0;
                    }
                  }
                  newboard[i][j] = (char) (digit + 48);
                  return 1;
              }
          }
      }
      return -1;
    }
    
    int _solveSudoku(vector<vector<char>>& board, vector<vector<char>> newboard)
{
        for (int i = 1; i < 10; i++) {
              int res = placeValidDigit(board, newboard, i);
              if (res < 0) {
                board = newboard;
                return 1;
              } else if (res > 0) {
                if (_solveSudoku(newboard, newboard)) {
                    board = newboard;
                    return 1;
                }
              }
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> newboard = board;
        _solveSudoku(board, newboard);
    }
};
