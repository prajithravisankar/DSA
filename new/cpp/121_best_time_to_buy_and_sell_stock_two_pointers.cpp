class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // idea: two pointers
        // left = buy day
        // right = sell day
        // find profits for all sell (right) > buy (left) as long as right < prices.size()
        // if right is not gt left, then make left = right
        // move right to next each iteration
        int left_buy_day = 0;
        int right_sell_day = 1;
        int profits = 0;

        while (right_sell_day < prices.size()) {
            int buy = prices[left_buy_day];
            int sell = prices[right_sell_day];
            if (buy < sell) {
                profits = max(profits, sell - buy);
            } else {
                left_buy_day = right_sell_day;
            }
            right_sell_day += 1;
        }

        return profits;
    }

    // time: O(n)
    // space: O(1)
};
