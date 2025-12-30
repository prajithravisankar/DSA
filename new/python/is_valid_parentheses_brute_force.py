class Solution:
    def isValid(self, s: str) -> bool:
        # idea: loop until () or {} or [] in the given string, replace it with ''
        # get out of the loop when all the brackets are gone and check if the resulting string
        # is empty, if empty, we have valid paranthesis, if not we have invalid parantheses
        while "()" in s or "[]" in s or "{}" in s:
            s = s.replace("()", "")
            s = s.replace("[]", "")
            s = s.replace("{}", "")
        return s == ""
        # time: O(n^2) because s.replace iterates each string once, and we are doing that
        # until all the parentheses types are gone.
        # space: O(n), string operations in python creates new string.
