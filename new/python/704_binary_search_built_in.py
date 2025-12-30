import bisect


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # idea: using built in functions
        index = bisect.bisect_left(nums, target)
        return index if (index < len(nums) and nums[index] == target) else -1

    # time: O(logn) - internally bisect.bisect_left uses binary search (lower bound)
    # space: O(1)
