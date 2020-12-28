class Solution {
public:
    bool _searchMatrix(const vector<vector<int>>& matrix, const int minrow,
const int maxrow, const int mincol, const int maxcol, const int target) {
        const int rowdiff = maxrow - minrow;
        if (!rowdiff) {
            return false;
        }
        const int coldiff = maxcol - mincol;
        if (!coldiff) {
            return false;
        }
        const int rowmid = rowdiff/2 + minrow;
        const int colmid = coldiff/2 + mincol;
        const int cur = matrix[rowmid][colmid];
        if (cur == target) {
            return true;
        } else if (cur > target) {
            return _searchMatrix(matrix, minrow, rowmid, mincol, maxcol, target)
||
                   _searchMatrix(matrix, minrow, maxrow, mincol, colmid,
target);
        } else {
            return _searchMatrix(matrix, rowmid + 1, maxrow, mincol, maxcol,
target) ||
                   _searchMatrix(matrix, minrow, maxrow, colmid + 1, maxcol,
target);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (!m) {
            return false;
        }
        const int n = matrix[0].size();
        int minrow = 0;
        int maxrow = m;
        int mincol = 0;
        int maxcol = n;
        return _searchMatrix(matrix, minrow, maxrow, mincol, maxcol, target);
    }
};
