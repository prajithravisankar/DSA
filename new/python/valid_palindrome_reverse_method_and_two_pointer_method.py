class Solution:
    def isPalindrome(self, s: str) -> bool:
        # method 1: reverse the given string stripping away all the non alnum chars
        # checkking if the reversed string is the same as the original string w/o
        # all the alnum chars. time: O(n) and space: O(n) because we are storing
        # extra string (reversed string).

        # method 2: using two pointers
        # if the current left pointer and right pointer points to same char
        # do this while left and right don't meet. if not alnum, skip it.

        # method 1:
        # reverse = ""
        # for c in s:
        #     if c.isalnum():
        #         reverse += c.lower()

        # return reverse == reverse[::-1]
        # time: O(n), space: O(n)

        # method 2:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not self.isAlphaNumeric(s[l]):
                l += 1
            while r > l and not self.isAlphaNumeric(s[r]):
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l, r = l + 1, r - 1

        return True

    # time: O(n), space: O(1)

    def isAlphaNumeric(self, c: str) -> bool:
        return (
            (ord("A") <= ord(c) <= ord("Z"))
            or (ord("a") <= ord(c) <= ord("z"))
            or (ord("0") <= ord(c) <= ord("9"))
        )
