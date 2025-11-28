class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # idea: recursion (dfs)
        # ["4", "5", "2", "/", "+"]

        # We always pop from the RIGHT side (end of the list).
        # If the popped value is a NUMBER → return it immediately.
        # If the popped value is an OPERATOR → recursively evaluate:
        #       first its RIGHT operand,
        #       then its LEFT operand.

        # Walkthrough:

        # 1st pop: "+"   → operator → evaluate right subtree
        # 2nd pop: "/"   → operator → evaluate right subtree
        # 3rd pop: "2"   → number   → return 2  (this becomes the RIGHT operand of "/")
        # 4th pop: "5"   → number   → return 5  (this becomes the LEFT operand of "/")

        # Now evaluate this subtree:  5 / 2

        # Back to "+":
        # 5th pop: "4"   → number   → return 4  (this becomes the LEFT operand of "+")

        # Final expression:  4 + (5 / 2)
        def dfs():
            token = tokens.pop()
            if token not in "+-*/":
                return int(token)

            right = dfs()
            left = dfs()

            if token == "+":
                return left + right
            if token == "-":
                return left - right
            if token == "*":
                return left * right
            if token == "/":
                return int(left / right)

        return dfs()
        # time: O(n)
        # space: O(n)
