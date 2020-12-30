class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int lcount = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            const char curr = s[i];
            if (curr == ')') {
                if (lcount == 0) {
                    len--;
                    s.erase(i, 1);
                    i--;
                } else {
                    lcount--;
                }
            } else if (curr == '(') {
                lcount++;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            if (!lcount) {
                break;
            }
            const char curr = s[i];
            if (curr == '(') {
                s.erase(i, 1);
                lcount--;
            }
        }
        return s;
    }
};
