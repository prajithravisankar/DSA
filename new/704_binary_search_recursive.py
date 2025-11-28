class Solution:
    def binary_search_recursion(self, left, right, nums, target):
        if left > right:
            return -1

        middle = left + (right - left) // 2
        if nums[middle] == target:
            return middle
        elif nums[middle] < target:
            return self.binary_search_recursion(middle + 1, right, nums, target)
        else:
            return self.binary_search_recursion(left, middle - 1, nums, target)

    def search(self, nums: List[int], target: int) -> int:
        # idea: binary search using recursion
        # create helper function that does recursive binary search
        # the helper function should track left, right, original array, and result
        # we return the index of the result throught that helper array
        # [0, 1, 3, 4, 7, 9], and 4 -> 3
        # [0, 1, 3, 4, 7, 9], and 5 -> -1
        # [], and 10 -> -1
        # [5] and 10 -> -1
        if len(nums) == 0:
            return -1
        elif len(nums) == 1 and nums[0] != target:
            return -1
        else:
            return self.binary_search_recursion(0, len(nums) - 1, nums, target)
        # time: O(logn)
        # space: O(logn)
