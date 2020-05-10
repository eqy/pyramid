class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (!m) {
            return 0;
        }
        const int n = grid[0].size();
        if (!n) {
            return 0;
        }
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int from_left = INT_MAX;
                int from_up = INT_MAX;
                if (i - 1 >= 0) {
                    from_left = dp[i-1][j];
                }
                if (j - 1 >= 0) {
                    from_up = dp[i][j-1];
                }
                int min = from_left > from_up ? from_up : from_left;
                if (i || j) {
                    dp[i][j] = min + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
