class Solution:
    def isValid(self, s: str) -> bool:
        # idea: create a map of closing parentheses to openeing parentheses. loop the string, if the char
        # not in the map, then it is not closing parentheses, it is opening parentheses, add it to the stack
        # of opening parentheses. if it is in the map, and the map, and stack not empty, and the char maps
        # to the one at the top of the stack, then we can pop the stack.
        # finally return true if the stack is empty, if not return false.
        stack = []  # contains opening parentheses.
        map = {
            ")": "(",
            "]": "[",
            "}": "{",
        }  # this is a map of closing parentheses -> opening parentheses.
        for ch in s:
            if ch in map:
                if stack and map[ch] == stack[-1]:
                    stack.pop()
                else:
                    return False  # if stack is empty, return False, or the closing bracket does not
                    # match the opening bracket in stack return False.
            else:
                stack.append(ch)

        return True if not stack else False
        # time: O(n) because we go through the string using for loop
        # space: O(n) because we use stack.
