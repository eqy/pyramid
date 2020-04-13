#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int len = height.size();
        int global_max = 0;
        for (int i = 0; i < len; i++) {
            if (height[i] > global_max) {
                global_max = height[i];
            }
        }
        int max = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = len - 1; j > i; j--) {
                const int xdiff = j-i;
                if ((xdiff * global_max) < max) {
                    break;
                }
                int area = xdiff * (height[i] > height[j] ? height[j] : height[i]);
                if (area > max) {
                    max = area;
                }
            }
        } 
        return max;
    }
};

int main(void) {
    std::vector<int> test = {1,8,6,2,5,4,8,3,7};
    std::cout << Solution().maxArea(test) << std::endl;
}
