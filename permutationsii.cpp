#include <iostream>
#include <vector>
#include <set>


using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int len = nums.size();
        if (len <= 1) {
            return {nums};
        }
        std::set<std::vector<int>> unique;
        std::vector<std::vector<int>> res; 
        for (int i = 0; i < len; i++) {
            const int cur = nums[i];
            std::vector<int> temp = std::vector<int>(nums);
            temp.erase(temp.begin() + i);
            std::vector<std::vector<int>> tempres = permuteUnique(temp);
            for (auto it = tempres.begin(); it != tempres.end(); it++) {
                it->insert(it->begin(), cur);
                if (unique.find(*it) == unique.end()) {
                    unique.insert(*it);
                    res.push_back(*it); 
                }
            }
        }
        return res;
    }
};


int main(void) {
    std::vector<int> nums = {1, 1, 1, 2, 3, 4, 5, 6};
    auto res = Solution().permuteUnique(nums);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
