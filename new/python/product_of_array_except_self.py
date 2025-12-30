class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # approach 1: brute force, multiply everything except current index
        # and store it in the current index: O(n^2) not the most efficient one

        # approach 2: using division.
        # count zeros, if more than 1 zero, solution is array of 0s.
        # find the product of all the values in the array. Divide by current num
        # and store it in current num. need to track zeros. It is given in the
        # question to not use this method.

        # ===========> approach 3: prefix and suffix method <==========
        # calculate prefix and suffix of current num
        # do this for all the num.
        # resulting array should be the multiplication of prefix and suffix of the
        # current num.
        # optimal implementation of this method will give O(n) and
        # O(1) extra space (output array is not taken into account)

        output = [1] * len(nums)  # as per the question this won't be counted
        # as n extra space

        prefix = 1
        for i in range(1, len(nums) + 1):
            output[i - 1] = prefix
            prefix = prefix * nums[i - 1]

        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            output[i] = postfix * output[i]
            postfix = postfix * nums[i]

        return output
        # time: O(n)
        # space: O(1)
