class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # using hashmap one pass
        # create an empty hashmap called prev, where will will put previous visited values
        # if when finding out difference, if the difference is one of the previous visited values in hash map
        # then return those indices
        previously_visited = {}
        for i, val in enumerate(nums):
            difference = target - nums[i]
            if difference in previously_visited:
                return [previously_visited[difference], i]
            previously_visited[val] = i
        return []
        # time: O(n)
        # space: O(n)
