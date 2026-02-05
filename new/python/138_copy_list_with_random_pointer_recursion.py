"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    """
    idea: recursion
    use a hashmap of key (current given list) to value (copy of the given value)
    use recursion to get to the end until we reach the null node, in this step we will set the next pointer of the
    deep copy node using the current node's next pointer
    when we reach the null node, return to get to previous node in the stack and set the random pointer
    """

    def __init__(self):
        self.map = {}

    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if head is None:
            return None
        # the below if block checks for any cycles in the linked list, but it seems it is not necessary.
        if head in self.map:
            return self.map[head]

        copy = Node(head.val)
        self.map[head] = copy
        copy.next = self.copyRandomList(head.next)
        copy.random = self.map.get(head.random)
        return copy
