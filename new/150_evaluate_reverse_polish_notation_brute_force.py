class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # idea: brute force
        # while loop until we have exactly one element in the given array
        # for loop inside the while loop to iterate through each element and until we hit one of the symbols:
        # "+-*/"
        # if we hit the symbol, then 2 positions before the symbol is a, one position before the symbol is b
        # calculate relevant output, a + b, a - b, a * b, a / b
        # convert it to string, place it in the correct position [:i-2] + [result] + [i+1:], return the array
        while len(tokens) > 1:
            for i in range(len(tokens)):
                if tokens[i] in "+-*/":
                    a = int(tokens[i - 2])
                    b = int(tokens[i - 1])
                    if tokens[i] == "+":
                        result = a + b
                    elif tokens[i] == "-":
                        result = a - b
                    elif tokens[i] == "*":
                        result = a * b
                    elif tokens[i] == "/":
                        result = int(a / b)  # have to do integer division
                    tokens = tokens[: i - 2] + [str(result)] + tokens[i + 1 :]
                    break
        return int(tokens[0])
        # time: O(n^2)
        # space: O(n)
