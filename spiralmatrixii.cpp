#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        const int square = n*n;
        int cur = 1;
        int state = 0; // right
        int row = 0;
        int col = 0;
        while (cur <= square) {
            res[row][col] = cur;
            cur++;
            switch (state) {
                case 0: // right
                    col++;
                    if (col >= n || res[row][col]) {
                        col--;
                        state = 1; // down
                        row++;
                    }
                    break;
                case 1: // down
                    row++;
                    if (row >= n || res[row][col]) {
                        row--;
                        state = 2; // left
                        col--;
                    }
                    break;
                case 2: // left
                    col--;
                    if (col < 0 || res[row][col]) {
                        col++;
                        state = 3; // up
                        row--; 
                    }
                    break;
                case 3: // up
                    row--;
                    if (row < 0 || res[row][col]) {
                        row++;
                        state = 0; // right
                        col++;
                    }
                    break;
            }       
        } 
        return res; 
    }
};


int main(void) {
    auto res = Solution().generateMatrix(0);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    res = Solution().generateMatrix(10);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
