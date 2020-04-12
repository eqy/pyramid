#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
       const int len = s.size();
       const int col_chunk = max(numRows - 1, 1);
       const int chars_per_chunk = max(numRows + (col_chunk - 1), 1);
       const int cols = ((len/chars_per_chunk) + 1)*col_chunk;
       const int rows = numRows;
       char * matrix = new char[rows*cols];
       for (int i = 0; i < rows * cols; i++) {
            matrix[i] = 0;
       }
       int r = 0;
       int c = 0;
       std::string result;
       for (int i = 0; i < len; i++) {
            matrix[r*cols + c] = s[i];
            if (!(c % col_chunk) && r < (rows - 1)) {
                r++;
            } else {
                if (r > 0) {
                    r--;
                }
                c++;
            }
       }
       for (r = 0; r < rows; r++) {
            for (c = 0; c < cols; c++) {
                if (matrix[r*cols + c]) {
                    result.push_back(matrix[r*cols + c]);
                }
            }
       }
       delete[] matrix;
       return result; 
    }
};

int main(void) {
    std::cout << Solution().convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << Solution().convert("", 1) << std::endl;
    std::cout << Solution().convert("AB", 1) << std::endl;
}
