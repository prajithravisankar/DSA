class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # idea: binary search
        # iterate through each number in the list (O(n))
        # for each number (our current number), from its number next to the end, find the complement of
        # our current number through binary search (O(logn))
        # if we find the value it will be the index of our current number, and middle number's index (+ 1 since 1 based)
        for i in range(len(numbers)):  # O(n)
            left, right = i + 1, len(numbers) - 1
            value_to_find = target - numbers[i]
            while left <= right:  # O(log(n))
                middle = left + (right - left) // 2  # floor division in python
                # (9 // 4 -> 2.25 -> 2) and (-9 // 4 -> -2.25 -> -3)
                if numbers[middle] == value_to_find:
                    return [i + 1, middle + 1]
                elif numbers[middle] < value_to_find:
                    left = middle + 1
                else:
                    right = middle - 1
        return []
        # time: O(nlogn)
        # space: O(1)
