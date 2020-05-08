#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
    
    string getPermutation(int n, int k) {
        string res = "";
        int div = n;
        std::vector<int> possible;
        for (int i = 1; i <= n; i++) {
            possible.push_back(i);
        }
        k--;
        for (int i = 1; i <= n; i++) {
            const int fact_n_1 = fact(n-i);
            int cur_idx = k / fact_n_1;
            k = k % fact_n_1;
            int cur = possible[cur_idx];
            possible.erase(possible.begin() + cur_idx);
            res += std::to_string(cur);
        }
        return res;
    }
};

int main(void) {
    for (int i = 0; i < Solution().fact(9); i++) {
        auto res = Solution().getPermutation(9, i+1);
        std::cout << res << std::endl;
    }
    return 0;
}
