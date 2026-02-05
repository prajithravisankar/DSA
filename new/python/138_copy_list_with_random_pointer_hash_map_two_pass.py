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
        """
        idea: hash map two pass
        first pass to put the copy nodes in the hash map
        second pass is to connect next and random pointers using the original linked list.
        """
        original_to_copy = {
            None: None
        }  # we need to have None: None here because, in the second while loop we are accessing the dictionary using
        # this [] instead of .get(). Direct access crashed if the key doesn't exist.
        curr = head
        while curr:
            copy = Node(curr.val)
            original_to_copy[curr] = copy
            curr = curr.next

        curr = head
        while curr:
            original_to_copy[curr].next = original_to_copy[curr.next]
            original_to_copy[curr].random = original_to_copy[curr.random]
            curr = curr.next

        return original_to_copy[head]
        # time: O(n)
        # space: O(n)
