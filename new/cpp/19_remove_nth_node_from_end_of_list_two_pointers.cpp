/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // idea: two pointers (dummy node)
        // use a dummy node that points to head (a node before head)
        // use left and right pointer. 
        // make left point to dummy
        // and right point to head. 
        // now move right by exactly n nodes to the right
        // now move both left and right until right reaches nullptr
        // if right is at the end, then left is one before the node to be removed,
        // use left->next and left->next->next to remove the node and return 
        // !!!! dummy->next;

        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
    // time: O(n)
    // space: O(1)
};
