class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # if they don't have same length they cannot be a anagram
        # else, sort them and check if they are equal
        if len(s) != len(t):
            return False

        return sorted(s) == sorted(t)
        # time: O(nlogn + mlogm) = O(nlogn) because both have same length
        # space: depending on sorting technique: O(1) or O(n), in python O(n) sorting
        # always returns a new list
