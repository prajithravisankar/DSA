class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // idea: brute force
        // calculate profits for each buy and sell day where buy day < sell day
        int profits = 0;
        for (int buy_day = 0; buy_day < prices.size(); buy_day++) {
            int buy_price = prices[buy_day];
            for (int sell_day = buy_day + 1; sell_day < prices.size(); sell_day++) {
                int sell_price = prices[sell_day];
                profits = max(profits, sell_price - buy_price);
            }
        }

        return profits;
    }
    // time: O(n^2)
    // space: O(1)
};
