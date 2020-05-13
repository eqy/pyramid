class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (!n) {
            return;
        }
        const int m = matrix[0].size();
        if (!m) {
            return;
        }
        // traverse cols
        for (int j = 0; j < m; j++) {
            bool zero = false;
            bool allzero = true;
            for (int i = 0; i < n; i++) {
                if (!matrix[i][j]) {
                    zero = true;
                }
                if (matrix[i][j]) {
                    allzero = false;
                }
            }
            if (allzero) {
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        matrix[x][y] = 0;
                    }
                }
                return;
            }
            if (zero) {
                for (int i = 0; i < n; i++) {
                    if (matrix[i][j]) {
                        matrix[i][j] = 0;
                    } else {
                        matrix[i][j] = -1;
                    }
                }
            }
        }
        // traverse rows
        for (int i = 0; i < n; i++) {
            bool zero = false;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    bool zeroed = true;
                    for (int k = 0; k < n; k++) {
                      if (matrix[k][j] != -1 && matrix[k][j] != 0) {
                          zeroed = false;
                          break;
                      }
                    }
                    if (zeroed) {
                        zero = true;
                    }
                }
                if (zero) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
            }
        }
    }
};
