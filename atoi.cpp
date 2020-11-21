class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int size = str.size();
        if (!size) {
            return res;
        }
        int digit_found = 0;
        for (int i = 0; i < size; i++) {
            if (str[i] == ' ') {
                if (digit_found) {
                    break;
                }
                continue;       
            } else if (str[i] == '-') {
                if (digit_found) {
                    break;
                }
                sign *= -1;
                digit_found = 1;
            } else if (str[i] == '+') {
                if (digit_found) {
                    break;
                }         
                sign *= 1;
                digit_found = 1;
            } else {
                int digit = str[i] - 48;
                if (digit >= 0 && digit <= 9) {
                    digit_found = 1;
                    if (((long long) res * 10 + digit) * sign <= INT_MIN) {
                        return INT_MIN;
                    } else if (((long long) res * 10 + digit) * sign >= INT_MAX)
{
                        return INT_MAX;
                    } else {
                        res = res*10 + digit;
                    }
                } else {
                    break;
                }
            }
        }
        return sign*res;
    }
};
