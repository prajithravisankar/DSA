# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # idea: two pointers
        # create a dummy node and make left point to it as the previous value of head
        # make the right point to head
        # move right pointer exactly n steps forward as the first step
        # then move both left and right pointer until right reaches the end.
        # now left will be exactly one before the node to be removed, manipulate next pointers to remove the intended node
        dummy = ListNode(0, head)
        left = dummy  # this will save us from bugs, if we want to remove the head
        right = head

        while n != 0:
            right = right.next
            n -= 1

        while right:
            left = left.next
            right = right.next

        left.next = left.next.next

        return dummy.next  # returning the head pointer
        # time: O(n)
        # space: O(1)
