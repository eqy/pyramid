#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJumpHelper(vector<int>& nums, const int len, const int pos) {
        const int maxjump = nums[pos];
        if (pos == len - 1) {
            return true;
        }
        if (!maxjump) {
            return false;
        } else {
            for (int i = 1; i <= maxjump; i++) {
                const int newpos = pos + i;
                if (newpos == len - 1) {
                    return true;
                }
                if (newpos >= len) {
                    break;
                }
                if (nums[newpos] == maxjump - i) {
                    continue;
                }
                if (canJumpHelper(nums, len, newpos)) {
                    return true;
                }
            }
            return false;
        }

    }
    bool canJump(vector<int>& nums) {
        return canJumpHelper(nums, nums.size(), 0);
    }
};

int main(void) {
    std::vector<int> a = {2,3,1,1,4};
    std::vector<int> b = {3,2,1,0,4};
    std::cout << Solution().canJump(a) << std::endl;
    std::cout << Solution().canJump(b) << std::endl;
    return 0;
}
