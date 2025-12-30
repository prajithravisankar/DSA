class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # idea: brute force
        # track profits for each step
        # during each step of the iteration, find the difference between buying and selling of all possible combinations in the given
        # list following the rule (selling day > buying day)
        current_profit = 0
        for buy_date in range(len(prices)):
            buy = prices[buy_date]
            for sell_date in range(buy_date + 1, len(prices)):
                sell = prices[sell_date]
                current_profit = max(current_profit, sell - buy)

        return current_profit
        # time: O(n^2)
        # space: O(1)
