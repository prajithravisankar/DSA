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
        # idea: reverse and combine
        # break the linked list into two halves
        # reverse the second half of the linked list
        # combine first node from first linked list to first node from second linked list
        # to second node from first linked list to second node from second linked list ...

        # find the mid point to break the linked list
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # now slow points one before the middle node
        second = slow.next
        slow.next = None  # break the linked list into first and second linked list
        prev = None  # the prev pointer is going to be (later) the head of the second ll

        # reverse the second linked list
        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp

        # combine the first and second linked list, now prev is the head of the second ll
        first = head
        second = prev

        while second:
            temp1 = first.next
            temp2 = second.next
            first.next = second
            second.next = temp1
            first = temp1
            second = temp2

    # time: O(n)
    # space: O(1)
