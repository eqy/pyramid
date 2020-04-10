#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        string cur = "";
        std::set<char> cur_set;
        int end = 0;
        const int length = s.size(); 
        while (end < length) {
            const int cur_size = cur.size();
            const char end_char = s[end];
            if (cur_size) {
                if (cur_set.find(end_char) != cur_set.end()){
                    const int idx = cur.find(end_char);
                    if (idx < (cur_size - 1)) {
                        cur = cur.substr(idx+1);
                    } else {
                        cur = "";
                        cur_set.clear();
                    }
                }
            }
            cur_set.insert(end_char);
            cur.push_back(end_char);
            const int new_cur_size = cur.size();
            if (new_cur_size > longest) {
                longest = new_cur_size;
            }
            end++;
        }
        return longest;
    }
};


int main(void){
    std::cout << Solution().lengthOfLongestSubstring("abcabcbb") << std::endl;;
    std::cout << Solution().lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("bbbbb") << std::endl ;
    std::cout << Solution().lengthOfLongestSubstring("dvdf") << std::endl;
}
