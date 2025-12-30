class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # create a set and iteratively add elements if it is not
        # already there, if they are present return True
        # finally return false
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
        # Time complexity : O(n)
        # Space complexity : O(n)
