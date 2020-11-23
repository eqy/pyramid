class Solution {
public:
    string intToRoman(int num) {
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
"IX", "V", "IV", "I"};
        int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int len = 13;
        int pos = 0;
        string res = "";
        while (num >= 0 and pos < len) {
            int cur = num / vals[pos];
            if (cur > 0) {
                res.reserve(numerals[pos].length()*cur + res.length());
                for (int i = 0; i < cur; i++) {
                    res.append(numerals[pos]);
                }
            }
            num -= cur*vals[pos];
            pos++;
        }
        return res;
    }
};
