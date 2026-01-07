# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # idea: use slow and fast pointers
        # if two things are moving in a circle, and one is moving at 1x speed, and the second one is moving at 2x speed
        # then they will meet at some point
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True

        return False
        # time: O(n)
        # space: O(1)
