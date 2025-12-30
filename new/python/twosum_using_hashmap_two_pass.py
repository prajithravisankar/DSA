class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # go through the list and create a hashmap withe val: index
        # if we have duplicates in the list, the hashmap will have the recent index visited while iterating through it
        # again go through the list and get the difference between target and current number in the iteration
        # if that difference is present in the hashmap and that number is not the current number in our list iteration
        # then we found the pair. if the difference and the current iteration's number are same (they are the same number having
        # same index), then that is not the pair, move to next val.
        hash_map = dict()
        for i, val in enumerate(nums):
            hash_map[val] = (
                i  # this hashmap will have the most recent index for that value
            )

        for i, val in enumerate(nums):
            difference = target - nums[i]
            if difference in hash_map and hash_map[difference] != i:
                return [
                    min(i, hash_map[difference]),
                    max(i, hash_map[difference]),
                ]  # we don't have to check min or max because hashmap will have recent index
        # and we are iterating from the beginning.

        return []
        # time: O(n)
        # space: O(n) because we could have no duplicates in nums and thus create a hashmap of n items
