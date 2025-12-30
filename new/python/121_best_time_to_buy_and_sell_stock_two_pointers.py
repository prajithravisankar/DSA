class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # idea: two pointer
        # track buying and selling day using left and right pointers
        # left = buying day
        # right = selling day
        # if left < right, update max profits
        # if not make left point to right, because buying day is not less than selling day, so our selling day is lte, so we make that
        # our new buying day
        # move the selling day to the next day regardless
        # do this until we reach the end
        l_buying_day = 0
        r_selling_day = 1
        current_profits = 0

        while r_selling_day < len(prices):
            buy = prices[l_buying_day]
            sell = prices[r_selling_day]
            if buy < sell:
                current_profits = max(current_profits, sell - buy)
            else:
                l_buying_day = r_selling_day
            r_selling_day += 1

        return current_profits
        # time: O(n)
        # space: O(1)
