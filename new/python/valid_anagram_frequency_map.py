class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # check if they have same length if not they cannot be anagrams
        # if same length, create frequency map for first string
        # map the frequency of first string, go through it
        # go through the second string and reduce the count of frequency of frequency map
        # if the map after the end of the process has frequency map of all 0s it is anagram
        # if not they are not anagram

        if len(s) != len(t):
            return False

        frequency_counter = {}
        for i in range(0, len(s)):
            if s[i] in frequency_counter:
                frequency_counter[s[i]] += 1
            else:
                frequency_counter[s[i]] = 1

        # we don't even need this for loop we can do the step above itself.
        for j in range(0, len(s)):
            if t[j] in frequency_counter:
                frequency_counter[t[j]] -= 1
            else:
                return False

        for k in frequency_counter:
            if frequency_counter[k] != 0:
                return False

        return True
        # time complexity: O(n)
        # space complexity: O(1) if fixed alphabets if any type of characters O(n)
