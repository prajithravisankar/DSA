class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # idea: stack
        # use stack to track value and index of temperatures less than current
        # temperature, so we can find the difference between the current temperature
        # and lesser temperatures. We pop until we clear all the lesser temperatures
        # in the stack and update the list of days until higher temperature.
        # If current temperature is greater than the top
        # temperature in stack we do the above.
        # if not we add the current temperature to the stack and wait till greater temp
        # arrives.
        until = [0] * len(temperatures)
        stack = []
        for curr_index, curr_temp in enumerate(temperatures):
            while stack and curr_temp > stack[-1][0]:
                lesser_temp, lesser_index = stack.pop()
                until[lesser_index] = curr_index - lesser_index
            stack.append([curr_temp, curr_index])
        return until
        # time: O(n)
        # space: O(n)
