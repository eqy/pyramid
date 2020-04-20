#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            if (dividend == INT_MIN) {
                return INT_MAX;
            }
            return -dividend;
        }
    
        if (dividend > 0 && divisor > 0) {
           dividend = -dividend;
           divisor = -divisor; 
        } else if (dividend > 0) {
           dividend = -dividend;
           neg = true;
        } else if (divisor > 0) {
           divisor = -divisor;
           neg = true;
        }
        int quotient = 0;
        while (dividend < 0) {
           if (dividend <= divisor) {
                if (quotient == INT_MAX) {
                    if (neg) {
                        return -INT_MAX;
                    }
                    return INT_MAX;
                }
                quotient++;
           }
           dividend -= divisor;
        } 
        if (neg) {
            quotient = -quotient;
        }
        return quotient;
    }
};

int main(void) {
    std::cout << Solution().divide(10, 3) << std::endl;
    std::cout << Solution().divide(7, -3) << std::endl;
    std::cout << Solution().divide(-7, -3) << std::endl;
    std::cout << Solution().divide(-7, 3) << std::endl;
    std::cout << Solution().divide(999, 3) << std::endl;
    std::cout << Solution().divide(-2147483648, 1) << std::endl;

    return 0;
}
