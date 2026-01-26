# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # idea: two iteration
        # loop the ll two times
        # first time to find the length, if we have length then we can get the position to remove by N - n, where N = len of ll
        # second time to actually remove the node by manipulating the pointers' next pointer

        total_len = 0
        curr = head
        while curr:
            total_len += 1
            curr = curr.next

        remove_index = total_len - n

        if remove_index == 0:
            return head.next

        curr = head
        for i in range(0, remove_index):
            if i == remove_index - 1:
                curr.next = curr.next.next
            curr = curr.next

        return head
        # time: O(n)
        # space: O(1)
