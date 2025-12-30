class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # if not same length return false
        # create hash table
        # increament for first string and decrement for second string
        # if by the end the table is not 0, contains any other number, return false, else true
        # only works for small alphabetical characters
        if len(s) != len(t):
            return False

        hash_table = [0] * 26
        for i in range(len(s)):
            hash_table[ord(s[i]) - ord("a")] += (
                1  # ord return ascii value of a character ord('a') => 97
            )
            hash_table[ord(t[i]) - ord("a")] -= 1

        for val in hash_table:
            if val != 0:
                return False

        return True
        # time: O(n + m) = O(n) because both same length
        # space: O(1) because we only use 26 alphabets for this problem
