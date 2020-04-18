#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == nums[i+1]) {
                for (int j = i; j < len - 1; j++) {
                    nums[j] = nums[j+1];
                }
                len--;
                i--;
            }
        }
        return len;
    }
};

int main(void) {
    std::vector<int> nums = {1, 1, 2};
    int len = Solution().removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << std::endl;
    }
    std::cout << "??" << std::endl;
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    len = Solution().removeDuplicates(nums2);
    for (int i = 0; i < len; i++) {
        std::cout << nums2[i] << std::endl;
    }

}
