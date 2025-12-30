class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # idea: sliding window optimal
        # l = left pointer, r = right pointer, max_so_far = len of a substring window that doesn't have duplicate and is a window with max
        # substring in the given string
        # iterate through the given string, add the value of the r to the set,
        # if r is already in the set, remove the value of l from the set, and move l to next value, do this
        # until we get rid of the value of r from the set
        # BEFORE ADDING CURRENT r value to the set
        # now after getting rid of old r value from the set,
        # add current r value to the set, and continue with the iteration
        # in each iteration, calculate the size of the window: r - l + 1
        # update the max_so_far
        l, r, max_so_far = 0, 0, 0
        current_window = set()

        for r in range(len(s)):
            while s[r] in current_window:
                current_window.remove(s[l])
                l += 1
            current_window.add(s[r])
            max_so_far = max(max_so_far, r - l + 1)
        return max_so_far
        # time: O(n)
        # space: O(m)
