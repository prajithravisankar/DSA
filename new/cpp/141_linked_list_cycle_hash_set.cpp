/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // idea: hash set
        // if the current node, while itereating, already exists in the hashset, return true, else return false
        unordered_set<ListNode*> seen; // set of ListNode pointers, pointing to a node's address
        ListNode *curr = head;

        while (curr) {
            if (seen.find(curr) != seen.end()) {
                // then we found it, the iterator is not at the end (if at the end, the curr is not in the hashset)
                return true;
            }
            seen.insert(curr);
            curr = curr->next;
        }

        return false;
    }
    // time: O(n)
    // space: O(n)
};
