class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int levels = dp.size();
        if (!levels) {
            return 0;
        }
        if (levels == 1) {
            return triangle[0][0];
        }
        for (int level = levels - 2; level >= 0; level--) {
            const int n = level + 1;
            for (int idx = 0; idx <n; idx++) {
                const int temp = dp[level][idx];
                const int left = temp + dp[level+1][idx];
                const int right = temp + dp[level+1][idx+1];
                dp[level][idx] = left < right ? left : right;
            }
        }
        return dp[0][0];
    }
};

class SlowSolution {
public:
    int minimum(int previdx, int level, const int levels, vector<vector<int>> &triangle) {
        if (level == levels - 1) {
            return triangle[level][previdx] < triangle[level][previdx+1] ? triangle[level][previdx] : triangle[level][previdx+1];
        } else {
            const int left = triangle[level][previdx] + minimum(previdx, level + 1, levels, triangle);
            const int right = triangle[level][previdx + 1] + minimum(previdx + 1, level + 1, levels, triangle);
            return left < right ? left : right;
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        const int levels = triangle.size();
        if (!levels) {
            return 0;
        } else if (levels == 1) {
            return triangle[0][0];
        } else {
            return triangle[0][0] + minimum(0, 1, levels, triangle);
        }
    }
};
