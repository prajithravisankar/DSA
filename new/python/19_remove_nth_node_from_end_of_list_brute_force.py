# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # idea: brute force
        # put each node of the ll in an array
        # remove the nth from the back by manipulating next pointers

        curr = head
        nodes = []
        while curr:
            nodes.append(curr)
            curr = curr.next

        remove_index = len(nodes) - n

        if remove_index == 0:
            return head.next

        nodes[remove_index - 1].next = nodes[remove_index].next

        return head
        # time: O(n)
        # space: O(n)
