class DoublyLinkedNode:
    def __init__(self, val: int, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # idea: doubly linked node
        # create a doubly linked list out of the given tokens by iterating through each token in the tokens and making each token
        # a doubly linked node. connecting all the tokens to form a doubly linked list.
        # once we have doubly linked list, while loop the linked list and find the current node's value is a symbol "+-*/",
        # if it is a symbol, get a and b, left->left->val and left->val, and get the result for the symbol.
        # store the result of the value in the current node, and make current node's left point to left->left->left and then
        # now current node's left point to left->left->left, and make the current node's left point to the current node
        # (original left->left->left's right point to current node, just simply current->left->right = current node).
        # move the current to the next doubly linked node.
        head = DoublyLinkedNode(tokens[0], left=None, right=None)
        curr = head

        # make a doubly linked list
        for i in range(1, len(tokens)):
            curr.right = DoublyLinkedNode(tokens[i], left=curr, right=None)
            curr = curr.right

        curr = head
        while curr is not None:
            if curr.val in "+-*/":
                a = int(curr.left.left.val)
                b = int(curr.left.val)
                if curr.val == "+":
                    result = a + b
                elif curr.val == "-":
                    result = a - b
                elif curr.val == "*":
                    result = a * b
                else:
                    result = int(a / b)
                curr.val = str(result)

                curr.left = curr.left.left.left
                if curr.left is not None:
                    curr.left.right = curr  # successfully cut off the nodes that have values of a and b.

            value = curr.val
            curr = curr.right

        return int(value)
        # time: O(n)
        # space: O(n)
