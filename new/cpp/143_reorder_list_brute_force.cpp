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
        // idea: brute force
        // put the pointer to each node in the linked list in a dynamic array
        // then match the next pointer of the first node, to the last pointer
        // then last pointers next node to the first node, after first node moves to next place
        // set the last node's next to None (first pointer)
        if (!head) return;

        ListNode* curr = head;
        vector<ListNode*> nodes;

        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int first = 0;
        int last = nodes.size() - 1;

        while (first < last) {
            nodes[first]->next = nodes[last];
            first++;
            if (first >= last) {
                break;
            }
            nodes[last]->next = nodes[first];
            last--;
        }

        nodes[first]->next = nullptr;
    }
    // time: O(n)
    // space: O(n)
};
