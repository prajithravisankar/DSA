"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        # idea: space optimized (interleave and decouple)
        # instead of using hashmap to track and create a copy, we can create copy nodes and interleave them next to the original nodes and finally decouple them.
        # create copy nodes and make original nodes's next point to the copy nodes so it will be like this original->copy->original2->copy2->original3->copy3...
        # then make copy nodes random point to original nodes random.next (because random.next == a copy node of the original random node).
        # then finally decouple the original and copy nodes to form two seperate linked list, so we have a deep copy of the original node
        if head is None:
            return None

        original = head
        while original is not None:
            copy = Node(original.val)
            copy.next = original.next
            original.next = copy
            original = copy.next

        newHead = head.next

        original = head
        while original is not None:
            if original.random is not None:
                original.next.random = original.random.next
            original = original.next.next

        original = head
        while original is not None:
            copy = original.next
            original.next = copy.next
            if copy.next is not None:
                copy.next = copy.next.next
            original = original.next

        return newHead
        # time: O(n)
        # space: O(1) extra space, O(n) for the output
