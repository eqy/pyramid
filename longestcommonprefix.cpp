#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix;
        const int len = strs.size();
        if (!len) {
            return prefix;
        }
        while (true) {
           const int prefix_len = prefix.size();
           if (prefix_len == strs[0].size()) {
                return prefix;
           }
           char cur = strs[0][prefix_len];
           for (int idx = 0; idx < len; idx++) {
               const int cur_str_size = strs[idx].size();
               if (prefix_len == cur_str_size) {
                   return prefix;
               }
               const char cur_str_char = strs[idx][prefix_len];
               if (cur_str_char != cur) {
                   return prefix;
               }
           }
           prefix += cur;
        }
        return prefix; 
    }
};

int main(void) {
    std::vector<std::string> test = {"flower", "flow", "flight"};
    std::vector<std::string> test2 = {"dog", "racecar", "car"};
    std::vector<std::string> test3 = {};
    std::cout << Solution().longestCommonPrefix(test) << std::endl;
    std::cout << Solution().longestCommonPrefix(test2) << std::endl;
    std::cout << Solution().longestCommonPrefix(test3) << std::endl;
}
