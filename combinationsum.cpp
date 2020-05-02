#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public: 
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            std::sort(candidates.begin(), candidates.end());
            const int len = candidates.size();
            std::vector<std::vector<int>> solns;
            for (int i = 0; i < len; i++) {
                const int cur = candidates[i];
                if (cur == target) {
                    solns.push_back({cur});
                } else if (cur < target) {
                    std::vector<std::vector<int>> partials = combinationSum(candidates, target - cur);
                    for (auto it = partials.begin(); it != partials.end(); it++) {
                        if ((*it)[0] < cur) {
                            continue;
                        }
                        it->insert(it->begin(), cur);
                        solns.push_back(*it);
                    }
                }
            } 
            return solns;    
        }
};

int main(void) {
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto res = Solution().combinationSum(candidates, target);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    candidates = {2, 3, 5};
    target = 8;
    res = Solution().combinationSum(candidates, target);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
