class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # idea: brute force
        # given an array of size >= 3, first sort them, (this avoids having duplicates of
        # of different order, if we have duplicates we can eliminate using a set this way)
        # iterate through each element and find the triplets that add up to 0
        # put the triplet in a set to ensure unique triplets (also convert to tuple, sets don't
        # accept unhashables).
        # once done return the list version of all the tuples in the set.
        if len(nums) < 3:
            return []

        result = set()
        nums.sort()  # also sorting prevents us from having these different triplets: [-1, 0, 1] and [-1, 1, 0]
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        result.add(
                            tuple([nums[i], nums[j], nums[k]])
                        )  # we need to make a tuple because list is not hashable

        return [list(i) for i in result]
        # time: O(n^3), where n is the number of elements in the array
        # space: O(m), where m is the maximum number of triplets at the result set.
