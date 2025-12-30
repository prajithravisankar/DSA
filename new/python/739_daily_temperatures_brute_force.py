class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # idea: brute force
        # +1 until we have a day greater than current day,
        # if we reach the end before getting a higher temp than current day
        # set the count to 0.
        until = []
        for i in range(len(temperatures)):
            j = i + 1
            count = 1
            while j < len(temperatures):
                if temperatures[i] < temperatures[j]:
                    break
                count += 1
                j += 1
            if j == len(temperatures):
                until.append(0)
            else:
                until.append(count)
        return until
        # time: O(n^2)
        # space: O(n)
