#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    void helper(string cur, int n, int open, int close, std::vector<string> &res) {
        if (close == n) {
            res.push_back(cur);
        } else {
            if (open == n) {
                std::string newcur = cur + ")";
                helper(newcur, n, open, close + 1, res); 
            } else {
                if (open > close) {
                    std::string newcur = cur + ")";
                    helper(newcur, n, open, close + 1, res);
                }
                std::string newcur = cur + "(";
                helper(newcur, n, open + 1, close, res);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        helper("", n, 0, 0, res);
        return res;
    }
};

int main(void) {
    auto res = Solution().generateParenthesis(0);
    for (auto it = res.begin(); it != res.end(); it++) {
        std::cout << *it << std::endl;
    } 
    return 0;
}
