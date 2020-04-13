#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
       int paren_count = 0;
       int brace_count = 0;
       int bracket_count = 0;
       const int len = s.size();
       for (int i = 0; i < len; i++) {
            const char cur = s[i];
            switch (cur) {
                case '(' :
                    paren_count++;
                    break;
                case ')' :
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] == '(') {
                            s[j] = ' ';
                            s[i] = ' ';
                            break;
                        } else if (s[j] != ' ') {
                            return false;
                        }
                    }
                    paren_count--;
                    break;
                case '{' :
                    brace_count++;
                    break;
                case '}' :
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] == '{') {
                            s[j] = ' ';
                            s[i] = ' ';
                            break;
                        } else if (s[j] != ' ') {
                            return false;
                        }
                    }
                    brace_count--;
                    break; 
               case '[' :
                    bracket_count++;
                    break;
               case ']' :
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] == '[') {
                            s[j] = ' ';
                            s[i] = ' ';
                            break;
                        } else if (s[j] != ' ') {
                            return false;
                        }
                    }
                    bracket_count--;
                    break;
            }
            if (paren_count < 0 || brace_count < 0 || bracket_count < 0) {
                return false;
            }
       }
       if (paren_count || brace_count || bracket_count) {
            return false;
       }
       return true;
    }
};


int main(void) {
    std::cout << Solution().isValid("()") << std::endl;
    std::cout << Solution().isValid("()[]{}") << std::endl;
    std::cout << Solution().isValid("(]") << std::endl;
    std::cout << Solution().isValid("([)]") << std::endl;
    std::cout << Solution().isValid("{[]}") << std::endl;
    std::cout << Solution().isValid("{[(({}))]}") << std::endl;
    std::cout << Solution().isValid("{[(({[}]))]}") << std::endl;
}
