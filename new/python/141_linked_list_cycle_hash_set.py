# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # idea: using hashset
        # use hashset to check if the current node's address exists in the hashset, if it exists, return true
        # if not return false.
        seen = set()
        curr = head
        while curr is not None:
            if curr in seen:
                return True
            else:
                seen.add(curr)
                curr = curr.next

        return False
        # time: O(n)
        # space: O(n)
