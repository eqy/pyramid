class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size();
        std::vector<std::vector<int>> result({{}});
        //std::vector<std::vector<int>> prev({{}});
        std::vector<int> prevtopidx({-1});
        int resultstart = 0;
        for (int k = 1; k <= length; k++) {
            std::vector<int> topidx;
            //std::vector<int> curr;
            const int result_len = result.size();
            int new_results = result_len - resultstart;
            for (int i = resultstart; i < result_len; i++) {
                std::vector<int> temp = result[i];
                temp.push_back(0);
                const int currtopidx = prevtopidx[i-resultstart];
                for (int j = 1; j + currtopidx < length; j++) {
                    temp[k-1] = nums[currtopidx + j];
                    topidx.push_back(currtopidx + j);
                    result.push_back(temp);
                }
            }
            resultstart += new_results;
            prevtopidx = topidx;  
        }
        return result;
    }
};
