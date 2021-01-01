class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxarea = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool ok = true;
                int checkdim = 1;
                while (i + checkdim <= m && j + checkdim <= n) {
                    for (int jj = 0; jj < checkdim; jj++) {
                        if (matrix[i+checkdim-1][j+jj] == '0') {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        for (int ii = 0; ii < checkdim - 1; ii++) {
                            if (matrix[i+ii][j+checkdim-1] == '0') {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (!ok) {
                        break;
                    } else {
                        int area = checkdim*checkdim;
                        if (area > maxarea) {
                            maxarea = area;
                        }
                    }
                    checkdim++;
                }
            }
        }
        return maxarea;
    }
};
