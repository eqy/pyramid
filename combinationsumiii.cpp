class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> currsums;
        std::vector<std::vector<int>> currcombos = {{}};
        for (int length = 1; length < k; length++) {
            std::vector<std::vector<int>> newcombos;
            std::vector<int> newsums; 
            const int currcombosiz = currcombos.size();
            for (int i = 0; i < currcombosiz; i++) {
                std::vector<int> combo = currcombos[i];
                combo.push_back(0);
                int j = 0;
                int combosum = 0;
                if (length > 1) {
                    j = combo[length-2];
                    combosum = currsums[i];
                }
                for (j = j + 1; j <= 9 - (k - length) + 1; j++) {
                    int newcombosum = combosum + j;
                    if (n - newcombosum <= j) {
                        break;
                    }
                    combo[length-1] = j;
                    newcombos.push_back(combo);
                    newsums.push_back(newcombosum);
                }
            }
            currsums = newsums;
            currcombos = newcombos;
        }

        std::vector<std::vector<int>> finalcombos;
        const int combolen = currcombos.size();

        for (int i = 0; i < combolen; i++) {
            if ((n - currsums[i]) > currcombos[i][k-2] && (n - currsums[i]) <
10) {
                currcombos[i].push_back(n - currsums[i]);
                finalcombos.push_back(currcombos[i]);
            }
        }
        return finalcombos;
    }
};
