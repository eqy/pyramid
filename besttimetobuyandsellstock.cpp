class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const size_t len = prices.size();
        if (!len) {
            return 0;
        }
        int maxprofit = 0;
        int min = prices[0];
        int max = prices[0];
        for (int i = 0; i < len; i++) {
            const int cur_price = prices[i];
            if (cur_price < min) {
                min = cur_price;
                max = cur_price;
            } else if (cur_price > max) {
                max = cur_price;
            }
            const int profit = max - min;
            if (profit > maxprofit) {
                maxprofit = profit;
            }
        }
        return maxprofit;
    }
};
