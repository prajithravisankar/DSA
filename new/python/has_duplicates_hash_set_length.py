class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # create a set from the list, and compare the lengths of set to list
        # if the set's length is less than list's length, then we have duplicates
        return len(set(nums)) < len(nums)
        # time complexity: O(n) b/c set(nums) internally creates hash map, and
        # checks if each element in the list is already there. Each operation is
        # O(1) and there are n elements in nums. O(n).
        # Space complexity: O(n), for the hash map
