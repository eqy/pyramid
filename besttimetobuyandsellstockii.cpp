class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        const int len = prices.size();
        if (!len) {
            return total_profit;
        }
        int buy = prices[0];
        int prev_profit = 0;
        for (int i = 0; i < len; i++) {
            const int cur = prices[i];
            const int profit = cur - buy;
            if (profit < prev_profit) {
                total_profit += prev_profit;
                prev_profit = 0;
                buy = cur;
            } else {
                prev_profit = profit;
            }
        }
        total_profit += prev_profit;
        return total_profit;
    }
};
