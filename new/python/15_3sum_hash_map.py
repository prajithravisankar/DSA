class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # idea: hashmap
        # sort the given array
        # create a defaultDict of ints to have as a frequency counter for all the items
        # seen during the current iteration.
        # for the first iteration, we are having the first number of the triplet
        # for the second iteration, we are having the second number of the triplet
        # once we have these two numbers target (3rd number) = -(first num + second num),
        # if the target value is present in the frequency counter, then that is the third
        # number and we have a valid triplet, add it to our result array that has all the valid
        # triplets.
        # also, we can skip the first and second iteration if the previous value is the same
        # as current iteration's value
        # [-1,0,1,2,-1,-4] -> [-4, -1, -1, 0, 1, 2]
        nums.sort()
        frequency_map = defaultdict(int)
        for i in range(len(nums)):
            frequency_map[nums[i]] += 1

        valid_triplets = []
        # first iteration
        for i in range(len(nums)):
            # first thing we should reduce the current iterations number
            # it means we have used this number for the first iteration
            frequency_map[nums[i]] -= 1
            # if current and previous values are same
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # second iteration
            for j in range(i + 1, len(nums)):
                frequency_map[nums[j]] -= 1
                if j - 1 > i and nums[j] == nums[j - 1]:
                    continue
                target = -(nums[i] + nums[j])
                if frequency_map[target] > 0:  # valid triplet exists
                    valid_triplets.append([nums[i], nums[j], target])

            # once we come out of the second iteration, we are ready to move to the
            # subsequent rounds of first iteration, but we need to update the
            # frequency counter for all the values used in the current second iteration
            for k in range(i + 1, len(nums)):
                frequency_map[nums[k]] += 1

        return valid_triplets
        # time: O(n ^ 2)
        # space: O(m)
