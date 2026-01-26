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
        // idea: two pass
        // first pass is to count how many nodes are there, then we know the node to be removed
        // will be at the length - n index
        // second pass is to remove the node at index len - n
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        int removeNode = len - n;

        if (removeNode == 0) {
            return head->next;
        }

        curr = head;
        for (int i = 0; i < len - 1; i++) {
            if (i == removeNode - 1) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }

        return head;
    }
    // time: O(n)
    // space: O(1)
};
