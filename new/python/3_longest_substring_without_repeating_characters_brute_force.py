class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # idea: brute force
        # have a max so far variable to track the longest valid substring.
        # iterate through the given string, for each character (starting point)
        # have a set to have list of seen characters from that starting point, if at any point, we see a duplicate character,
        # stop the loop, and update the max so far variable.
        max_so_far = 0
        for starting_index in range(len(s)):
            unique_set = set()
            for ending_index in range(starting_index, len(s)):
                if s[ending_index] in unique_set:
                    break
                else:
                    unique_set.add(s[ending_index])
            max_so_far = max(max_so_far, len(unique_set))

        return max_so_far
        # time: O(n * m)
        # space: O(m)
        # n - size of the given string
        # m - size of the longest substring that we find in the inner loop
