class Solution {
public:
    std::vector<set<pair<int, int>>> valid(const vector<vector<vector<set<pair<int, int>>>>> & dp2, const int i, const int j, const int ii, const int jj) {
        std::vector<set<pair<int, int>>> res;
        int count = 0;
        for (auto it = dp2[i][j].begin(); it != dp2[i][j].end(); it++) {
            if (it->find({ii, jj}) == it->end()) {
                res.push_back(*it);
                res[count].insert({i, j});
                count++;
            }
        }
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<vector<set<pair<int, int>>>>> dp2(m, vector<vector<set<pair<int, int>>>>(n, vector<set<pair<int, int>>> {}));
        const int wordlen = word.size();
        // init dp and dp2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (wordlen == 1) {
                        return true;
                    }
                    dp[i][j] = 0;
                    dp2[i][j].push_back(set<pair<int, int>> {});
                }
            }
        }
        bool proceed = true;
        for (int k = 1; k <= wordlen; k++) {
            /*
            std::cout << "=================" << std::endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    std::cout << " " << dp[i][j];
                }
                std::cout << std::endl;
            }
            */
            if (!proceed) {
                break;
            }
            const int val = k - 1;
            vector<vector<vector<set<pair<int, int>>>>> newdp2(m, vector<vector<set<pair<int, int>>>>(n, vector<set<pair<int, int>>> {}));
            vector<vector<int>> newdp(m, vector<int>(n, -1));
            proceed = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    const int dpval = dp[i][j];
                    if (dpval == val) {
                        if (j+1 < n && board[i][j+1] == word[k]) {
                            vector<set<pair<int, int>>> paths = valid(dp2, i, j, i, j+1);
                            if (paths.size()) {
                                proceed = true;
                                newdp[i][j+1] = k;
                                newdp2[i][j+1].insert(newdp2[i][j+1].end(), paths.begin(), paths.end());
                                //newdp2[i][j+1] = dp2[i][j];
                                //newdp2[i][j+1].insert({i, j+1});
                            }
                        }
                        if (j > 0 && board[i][j-1] == word[k]) {
                            vector<set<pair<int, int>>> paths = valid(dp2, i, j, i, j-1);
                            if (paths.size()) {
                                proceed = true;
                                newdp[i][j-1] = k;
                                newdp2[i][j-1].insert(newdp2[i][j-1].end(), paths.begin(), paths.end());
                            }
                        }
                        if (i+1 < m && board[i+1][j] == word[k]) {
                           vector<set<pair<int, int>>> paths = valid(dp2, i, j, i+1, j);
                           if (paths.size()) {
                                proceed = true;
                                newdp[i+1][j] = k;
                                newdp2[i+1][j].insert(newdp2[i+1][j].end(), paths.begin(), paths.end());
                            }
                        }
                        if (i > 0 && board[i-1][j] == word[k]) {
                           vector<set<pair<int, int>>> paths = valid(dp2, i, j, i-1, j);
                           if (paths.size()) {
                                proceed = true;
                                newdp[i-1][j] = k;
                                newdp2[i-1][j].insert(newdp2[i-1][j].end(), paths.begin(), paths.end());
                            }
                        }
                        if (proceed && k == wordlen - 1) {
                            return true;
                        }
                    }
                }
            }
            dp = newdp;
            dp2 = newdp2;
        }
        return false;
    }
};

class Solution {
public:
    
    bool _exist(const vector<vector<char>>& board, const int row, const int col, const string substr, vector<vector<bool>> &dp) {
        const char curr = board[row][col];
        if (curr != substr[0]) {
            return false;
        } else {
            const int substrlen = substr.size();
            if (substrlen <= 1) {
                return true;
            }
            string newsubstr = substr.substr(1, substrlen - 1);
            dp[row][col] = false;
            bool res = ((col > 0) && dp[row][col - 1] && _exist(board, row, col - 1, newsubstr, dp)) ||
                   ((col < board[0].size() - 1) && dp[row][col + 1] && _exist(board, row, col + 1, newsubstr, dp)) ||
                   ((row > 0) && dp[row - 1][col] && _exist(board, row - 1, col, newsubstr, dp)) ||
                   ((row < board.size() - 1) && dp[row + 1][col] && _exist(board, row + 1, col, newsubstr, dp));
            dp[row][col] = true;
            return res;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();

        //int pos = 0;
        vector<vector<bool>> dp(m, vector<bool>(n, true));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (_exist(board, i, j, word, dp)) {
                    return true;
                }
            }
        } 
        return false;
    }
};
