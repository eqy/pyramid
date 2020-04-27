#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        std::vector<char> res;
        const int alen = a.size();
        const int blen = b.size();
        const int len = alen > blen ? alen : blen;
        bool carry = false;
        for (int i = 0; i < len; i++) {
            int cur_a = 0;
            int cur_b = 0;
            if (i < alen) {
                cur_a = a[(alen-1)-i] == '1';
            }
            if (i < blen) {
                cur_b = b[(alen-1)-i] == '1';
            }
            if (cur_a && cur_b) {
                if (carry) {
                    res.insert(res.begin(), '1');
                } else {
                    res.insert(res.begin(), '0');
                }
                carry = true;
            } else if (cur_a || cur_b) {
                if (carry) {
                    res.insert(res.begin(), '0');
                    carry = true;
                } else {
                    res.insert(res.begin(), '1');
                    carry = false;
                }
            } else {
                if (carry) {
                    res.insert(res.begin(), '1');
                } else {
                    res.insert(res.begin(), '0');
                }
                carry = false;
            }
        }
        if (carry) {
            res.insert(res.begin(), '1');
        }
        return std::string(res.begin(), res.end());
    }
};

int main(void) {
    std::string first = "1010";
    std::string second = "1011";
    Solution().addBinary(first, second);
}
