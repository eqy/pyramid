class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        if (!m) {
            return 0;
        }
        const int n = obstacleGrid[0].size();
        if (!n) {
            return 0;
        }
        int dp[m][n];
        if (obstacleGrid[0][0]) {
            return 0;
        }
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = 0;
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                if ((i-1) >= 0 && !obstacleGrid[i-1][j]) {
                    cur += dp[i-1][j];
                }
                if ((j-1) >= 0 && !obstacleGrid[i][j-1]) {
                    cur += dp[i][j-1];
                }
                if (i || j) {
                    dp[i][j] = cur;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
