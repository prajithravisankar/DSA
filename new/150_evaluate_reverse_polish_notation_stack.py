class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # idea: stack
        # loop through the tokens
        # have a stack tracking all the operands
        # in the loop if the current token is an operand add it to the stack.
        # if the current token is and operator, pop the previous 2 elements and do the operation
        # for those 2 elements in correct order.
        stack = []
        for token in tokens:
            if token == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif token == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif token == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif token == "/":
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a / b))
            else:
                stack.append(int(token))

        return stack[0]
        # time: O(n)
        # space: O(n)
