ass Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        const int len = nums.size();
        if (len == 1) {
            res.push_back({nums[0]});
        } else {
            for (int i = 0; i < len; i++) {
                const int cur = nums[i];
                std::vector<int> temp(nums);
                temp.erase(temp.begin() + i);
                auto intermediate = permute(temp);
                for (auto it = intermediate.begin(); it != intermediate.end(); it++) {
                    it->insert(it->begin(), cur);
                    res.push_back(*it);
                }
            }
        }
        return res;
    }
};
