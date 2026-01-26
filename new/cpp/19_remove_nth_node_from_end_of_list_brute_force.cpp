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
        // idea: brute force
        // put all the nodes in an array
        // manipulate the node to be deleted by accessing node before it and node after it
        // connect these two nodes and return the head. 
        // if the head is to be removed, return head's next node. 
        vector<ListNode*> arr;
        ListNode* curr = head;
        while (curr != nullptr) {
            arr.push_back(curr);
            curr = curr->next;
        }

        int removeIndex = arr.size() - n;

        if (removeIndex == 0) {
            return head->next;
        }

        arr[removeIndex - 1]->next = arr[removeIndex]->next;
        return head;
    }

    // time: O(n)
    // space: O(n)
};
