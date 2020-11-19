#include <set>
#include <string>
#include <iostream>
#include <map>
#include <utility>

// using namespace std;

class Solution2 {
public:
    std::string prune(std::string s, std::string t) {
        std::string res;
        std::set<char> t_chars;
        for (auto it = t.begin(); it != t.end(); it++) {
            t_chars.insert((char) *it);
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            auto find_res = t_chars.find((char) *it);
            if (find_res != t_chars.end()) {
                res.append(1, *it);
            }
        }
        return res;
    }   
    
    int numDistinct(std::string s, std::string t) {
        // s = prune(s, t);
        long t_size = t.size();
        long s_size = s.size();
        if (!t_size or !s_size) {
            return 0;
        }
        if (s_size < t_size) {
            return 0;
        }
        if (s_size == t_size) {
            if (s == t) {
                return 1;
            }
            return 0;
        }
         
        for (long pos = 0; pos < s_size; pos++) {
            if ((char) (s[pos]) == (char) *(t.begin())) {
                if (t_size == 1) {
                    return 1 + numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t);
                } else {
                    return numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t.substr(1, t_size - 1)) + \
                           numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t);
                }
            }             
        }
        return 0;
    }
};

class Solution3 {
public: 
    int _numDistinct(std::string s, std::string t, std::map<std::pair<int,int>, int> &dp) {
        long t_size = t.size();
        long s_size = s.size();
        if (!t_size or !s_size) {
            return 0;
        }
        if (s_size < t_size) {
            return 0;
        }
        if (s_size == t_size) {
            std::pair<int, int> cur(s_size, t_size);
            auto dp_res = dp.find(cur);
            if (dp_res != dp.end()) {
                return dp_res->second;
            } else {
                dp.insert({cur, (int) (s == t)});
                return s == t;
            }
        }
        for (long pos = 0; pos < s_size; pos++) {
             if ((char) (s[pos]) == (char) *(t.begin())) {
                if (t_size == 1) {
                    std::pair<int, int> cur(s_size - (pos + 1), t_size);
                    auto dp_res = dp.find(cur);
                    if (dp_res != dp.end()) {
                        return 1 + dp_res->second;
                    } else {
                        int val = _numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t, dp);
                        dp.insert({cur, val});
                        return 1 + val;
                    }
                } else {
                    std::pair<int, int> cur1(s_size - (pos + 1), t_size - 1);
                    std::pair<int, int> cur2(s_size - (pos + 1), t_size);
                    int val1;
                    int val2;
                    auto dp_res1 = dp.find(cur1);
                    auto dp_res2 = dp.find(cur2);
                    if (dp_res1 != dp.end()) {
                        val1 = dp_res1->second;
                    } else {
                        val1 = _numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t.substr(1, t_size - 1), dp);
                        dp.insert({cur1, val1});
                    }
                    if (dp_res2 != dp.end()) {
                        val2 = dp_res2->second; 
                    } else {
                        val2 = _numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t, dp);
                        dp.insert({cur2, val2});
                    }
                    return val1 + val2;
                }
            }             
           
        }
        return 0;
    }
    
    int numDistinct(std::string s, std::string t) {
        std::map<std::pair<int, int>, int> dp;
        return _numDistinct(s, t, dp);
    }

};


class Solution {
public: 
    int _numDistinct(std::string &s, std::string &t, int s_pos, int t_pos, int s_size, int t_size, int *dp) {
        int cur_s_size = s_size - s_pos;
        int cur_t_size = t_size - t_pos;
        if (cur_t_size <= 0 or cur_s_size <= 0) {
            return 0;
        }
        if (cur_t_size > cur_s_size) {
            return 0;
        }
        if (cur_s_size == cur_t_size) {
            int idx = cur_s_size*t_size + cur_t_size; 
            int dp_res = dp[idx];
            if (dp_res >= 0) {
                return dp_res;
            } else {
                // dp.insert({cur, (int) (s == t)});
                dp[idx] = s.substr(s_pos, cur_s_size) == t.substr(t_pos, cur_t_size);
                return dp[idx];
            }
        }
        for (int pos = s_pos; pos < s_size; pos++) {
             if ((char) (s[pos]) == (char) t[t_pos]) {
                if (cur_t_size == 1) {
                    int idx = (s_size - pos - 1)*1024 + cur_t_size;
                    int dp_res = dp[idx];
                    if (dp_res >= 0) {
                        return 1 + dp_res;
                    } else {
                        // int val = _numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t, dp);
                        int val = _numDistinct(s, t, pos + 1, t_pos, s_size, t_size, dp);
                        dp[idx] = val;
                        return 1 + val;
                    }
                } else {
                    // std::pair<int, int> cur1(s_size - (pos + 1), t_size - 1);
                    // std::pair<int, int> cur2(s_size - (pos + 1), t_size);
                    int idx1 = (s_size - (pos + 1))*1024 + cur_t_size - 1;
                    int idx2 = (s_size - (pos + 1))*1024 + cur_t_size;
                    int val1;
                    int val2;
                    int dp_res1 = dp[idx1];
                    int dp_res2 = dp[idx2];
                    // auto dp_res1 = dp.find(cur1);
                    // auto dp_res2 = dp.find(cur2);
                    if (dp_res1 >= 0) {
                        val1 = dp_res1;
                    } else {
                        // val1 = numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t.substr(1, t_size - 1));
                        val1 = _numDistinct(s, t, pos + 1, t_pos + 1, s_size, t_size, dp);
                        dp[idx1] = val1;
                    }
                    if (dp_res2 >= 0) {
                        val2 = dp_res2;
                    } else {
                        // val2 = numDistinct(s.substr(pos + 1, s_size - (pos + 1)), t);
                        val2 = _numDistinct(s, t, pos + 1, t_pos, s_size, t_size, dp);
                        dp[idx2] = val2;
                    }
                    return val1 + val2;
                }
            }             
           
        }
        return 0;
    }
    
    int numDistinct(std::string s, std::string t) {
        // std::map<std::pair<int, int>, int> dp;
        int *dp = new int[1024*1024]; 
        std::fill(dp, dp + 1024*1024, -1);
        int val = _numDistinct(s, t, 0, 0, s.size(), t.size(), dp);
        delete [] dp; 
        return val;
    }
};


int main() {
    auto sol = Solution();
    std::cout << sol.numDistinct("rabbbit", "rabbit") << std::endl;
    std::cout << "done" << std::endl;
    std::cout << sol.numDistinct("babgbag", "bag") << std::endl;

}
