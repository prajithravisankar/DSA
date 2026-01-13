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
    void reorderList(ListNode* head) {
        // idea: reverse and merge
        // break the linked list into two halves using slow and fast pointer to get the midpoint
        // after breaking the ll, reverse the second half of the linked list
        // after breaking and reversing, combine first node of first ll to first node of second ll
        // and first node of second ll to second node of first ll, and second node of first ll to second
        // node of second ll ...

        // find the midpoint
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow points to one before the start of the second linked list
        ListNode* second = slow->next;
        slow->next = nullptr; // now cut the first and second ll into two seperate ll

        // reverse the second ll
        ListNode* prev = nullptr;
        ListNode* temp;
        while (second != nullptr) {
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // combine first ll and second ll alternatively
        ListNode* temp1;
        ListNode* temp2;
        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
    // time: O(n)
    // space: O(1)
};
