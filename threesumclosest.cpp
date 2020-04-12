#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int length = nums.size();
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < length; i++) {
            const int a = nums[i];
            for (int j = i + 1; j < length; j++) {
                const int b = nums[j];
               for (int k = j + 1; k < length; k++) {
                   const int c = nums[k];
                   const int cur_sum = (a + b + c);
                   if (abs(target - cur_sum) < abs(target - sum)) {
                        sum = cur_sum;
                   }
               } 
            }
        }
        return sum;
    }
};

int main(void) {
    std::vector<int> nums = {-1, 2, 1, -4};
    std::cout << Solution().threeSumClosest(nums, 1) << std::endl;
}
