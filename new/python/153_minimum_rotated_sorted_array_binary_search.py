class Solution:
    def findMin(self, nums: List[int]) -> int:
        # idea: binary search
        # the given array is rotated sorted array. Meaning there is a HIGH and a FALL and then a HIGH.
        # ex: 4,5,6,7,0,1,2, here 4, 5, 6, and 7, is sorted, and reaches high, and a fall happens at 0
        # and from 0, 1, 2, again a HIGH. So we have to figure out where the FALL happens.
        # each iteration split the given array into two equal parts. (splitting point is our middle index)
        # check if the parts are sorted in the parts split by the binary search
        # left part (left value <= middle value), then the minimum value cannot be in this part
        # because the FALL breaks the array into HIGH point and a LOW point. It cannot be sorted.
        # so the FALL must be in the other part split during binary search now update the indices accordingly,
        # and search the other part.
        minimum_in_sorted_rotated_array = nums[0]
        left = 0
        right = len(nums) - 1

        while left <= right:
            if (
                nums[left] < nums[right]
            ):  # elements are uniqe, should not be <=, should be <
                # we found the bracket where everything is sorted, so the minimum must be the left most value
                minimum_in_sorted_rotated_array = min(
                    minimum_in_sorted_rotated_array, nums[left]
                )
                break

            # split the given array to check which part is not sorted
            split_index = left + (right - left) // 2
            minimum_in_sorted_rotated_array = min(
                minimum_in_sorted_rotated_array, nums[split_index]
            )

            if nums[left] <= nums[split_index]:
                # then this part is sorted, the value cannot be in this part
                left = split_index + 1
            else:
                # else the right part of the split is sorted, and the min value cannot be in this part
                right = split_index - 1

        return minimum_in_sorted_rotated_array
        # time: O(logn)
        # space: O(1)
