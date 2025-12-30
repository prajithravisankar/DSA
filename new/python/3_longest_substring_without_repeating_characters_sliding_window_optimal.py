class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # idea: sliding window (optimal)
        # use a map to track the last position of the r pointer's duplicate value, and move l by NOTHING,
        # or to the right of the previous duplicate r value by 1, with this we don't have to use a while loop to move l one by one
        # until we remove the duplicate r value.
        l = 0
        r = 0
        index = {}
        max_so_far = 0

        for r in range(len(s)):
            if s[r] in index:
                l = max(index[s[r]] + 1, l)
            index[s[r]] = r
            max_so_far = max(max_so_far, r - l + 1)

        return max_so_far
        # time: O(n) - total length of string
        # space: O(m) - m is total unique characters in the string
