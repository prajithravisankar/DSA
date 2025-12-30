class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # idea: binary search using iteration
        # use while loop and left and right pointers to do binary search
        left = 0
        right = len(nums) - 1

        # should be left <= right because we might have an array of length = 1
        while left <= right:
            middle = left + (right - left) // 2
            if nums[middle] == target:
                return middle
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1

        return -1
        # time: O(logn)
        # space: O(1)
