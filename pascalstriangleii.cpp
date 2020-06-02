class Solution {
public:
    vector<int> getRow(int rowIndex) {

        std::vector<int> res;
        if (rowIndex < 0) {
            return res;
        } else if (!rowIndex) {
            return {1};
        } else if (rowIndex == 1) {
            res = {1, 1};
            return res;
        } else {
            std::vector<int> prev = {1, 1};
            for (int k = 2; k <= rowIndex; k++) {
                std::vector<int> cur(k+1);
                cur[0] = 1;
                cur[k] = 1;
                for (int i = 1; i < k; i++) {
                    cur[i] = prev[i-1] + prev[i];
                }
                prev = cur;
            }
            return prev;
        }
    }
};
