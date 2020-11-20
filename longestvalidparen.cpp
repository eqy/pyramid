class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> idx;
        int max = 0;
        int size = s.size();
        idx.push(-1);
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                idx.push(i);
            } else {
                  idx.pop();
                  if (!idx.size()) {
                      idx.push(i);
                  } else {
                      int cur = i - idx.top();
                      max = cur > max ? cur : max;
                  
                  }
            }
        }
        return max;
    }
};
