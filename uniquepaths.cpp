class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = 0;
                if ((i - 1) >= 0) {
                    cur += dp[i-1][j];
                }
                if ((j - 1) >= 0) {
                    cur += dp[i][j-1];
                }
                if (cur) {
                    dp[i][j] = cur;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
