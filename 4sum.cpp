#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int len = nums.size();
        std::unordered_map<int, int> count_list;
        std::set<std::array<int, 4>> res_set;
        std::vector<std::vector<int>> res;

//        for (int i = 0; i < len; i++) {
//           const int num = nums[i]; 
//           if (count_list.find(num) == count_list.end()) {
//               count_list[num] = 1;
//           } else {
//               count_list[num]++;
//           }
//        }
        
        for (int i = 0; i < len - 3; i++) {
            for (int j = i + 1; j < len - 2; j++) {
                for (int k = j + 1; k < len - 1; k++) {
                    for (int l = k + 1; l < len; l++) {
                        const int sum = (nums[i] + nums[j] + nums[k] + nums[l]);
                        if (sum == target) {
                            std::array<int, 4> cur = {nums[i], nums[j], nums[k], nums[l]}; 
                            std::sort(cur.begin(), cur.end(), std::less<int>());
                            res_set.insert(cur);
                        }
                        //const int inv = -(nums[i] + nums[j] + nums[k]);
                    }                            
                }
            }
        }
        res.reserve(res_set.size());
        for (auto it = res_set.begin(); it != res_set.end(); it++) {
            res.push_back(std::vector<int>(it->begin(), it->end()));
        }
        return res;
    }
};

int main(void) {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto res = Solution().fourSum(nums, target);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
}
