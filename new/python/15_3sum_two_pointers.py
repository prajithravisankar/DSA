class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # idea: two pointers
        # for every first number (should not be positive) find two other number using
        # two pointers for which the the three numbers together sum up to 0. After sorting
        # if the first number is not 0 or -ve value, then the following two numbers will also be
        # positive. No sum of three positive numbers will be positive.
        nums.sort()
        valid_triplet = []
        for i, val in enumerate(nums):
            if val > 0:  # if first number of the triplet from sorted array is +ve, we
                # cannot have sum of three number to be 0.
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = len(nums) - 1
            while left < right:
                total = val + nums[left] + nums[right]
                if total > 0:
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    valid_triplet.append([val, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while right > left and nums[right] == nums[right + 1]:
                        right -= 1

        return valid_triplet
        # time: O(n^2)
        # space: O(1 or n) depending or sorting algorithm nums.sort()
        #        O(m) for extra space for the output list
