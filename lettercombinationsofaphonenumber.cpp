#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> cur_prefixes;
        const std::vector<std::string> chars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        const int len = digits.size();
        for (int i = 0; i < len; i++) {
           std::vector<std::string> new_prefixes;
           const int digit = ((char) digits[i]) - 48;
           std::cout << digit << std::endl;
           const int cur_len = chars[digit].size();
           const int cur_prefixes_len = cur_prefixes.size();
           if (cur_prefixes_len) {
               for (int p = 0; p < cur_prefixes_len; p++) {
                   const std::string cur_prefix = cur_prefixes[p];
                   for (int j = 0; j < cur_len; j++) {
                       new_prefixes.push_back(cur_prefix + chars[digit].substr(j, 1)); 
                   }
               }
           } else {
               for (int j = 0; j < cur_len; j++) {
                   new_prefixes.push_back(chars[digit].substr(j, 1)); 
               }
           }
           cur_prefixes = new_prefixes;
        }
        return cur_prefixes;
    }
};

int main(void) {
    auto temp = Solution().letterCombinations("23");
    for (auto it = temp.begin(); it != temp.end(); it++) {
        std::cout << *it << std::endl;
    }
}
