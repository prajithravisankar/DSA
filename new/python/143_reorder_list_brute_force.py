# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # idea: brute force
        # put the linked list nodes in a list
        # now manipulate the indices with pointers to go zig zag from left end to right end.
        # taking care of the pointers, by increasing on the left end, and decreasing on the right end
        # until left pointer >= right pointer.
        if not head:
            return

        curr = head
        nodes = []
        while curr:
            nodes.append(curr)
            curr = curr.next

        left = 0
        right = len(nodes) - 1

        while left < right:
            nodes[left].next = nodes[right]
            left += 1
            if left >= right:
                break
            nodes[right].next = nodes[left]
            right -= 1

        nodes[left].next = None
        # time: O(n)
        # space: O(n)
