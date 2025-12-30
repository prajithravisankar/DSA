class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # using sorting
        # step 1: sort
        nums.sort()  # O(nlogn)

        # step 2: compare
        for i in range(1, len(nums)):  # O(n)
            if nums[i] == nums[i - 1]:
                return True

        return False
        # time complexity : O(nlogn) + O(n) = O(nlogn)
        # space complexity : if inplace sorting = O(1) else O(n)
