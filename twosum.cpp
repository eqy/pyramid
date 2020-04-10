#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i, j};
                }
            }
        }     
        return vector<int> {};
    }
};

int main(void) {
   std::vector<int> a = {3, 2, 4};
   auto res = Solution().twoSum(a, 6);
   if (res.size() > 0)
           std::cout << res[0] << res[1]; 
}
