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
        # idea: hash map one pass
        # use collections.defaultdict() to create a dummy node every time we need a next node to point to
        # in the next iteration set the value of the dummy node created as next node in the previous iteration. Set its value, next node (another dummy node),
        # and random pointer (if doesn't exist another dummy pointer)
        old_to_copy = collections.defaultdict(lambda: Node(0))
        old_to_copy[None] = None

        curr = head
        while curr:
            old_to_copy[curr].val = curr.val
            old_to_copy[curr].next = old_to_copy[curr.next]
            old_to_copy[curr].random = old_to_copy[curr.random]
            curr = curr.next

        return old_to_copy[head]
        # time: O(n)
        # space: O(n)
