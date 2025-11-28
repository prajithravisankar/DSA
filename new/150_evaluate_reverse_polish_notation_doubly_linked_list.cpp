class DoublyLinkedNode {
    public:
        string val;
        DoublyLinkedNode* prev;
        DoublyLinkedNode* next;

        DoublyLinkedNode(string val, DoublyLinkedNode* prev = nullptr, DoublyLinkedNode* next = nullptr) {
            this->val = val;
            this->prev = prev;
            this->next = next;
        }
};


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // idea: doubly linked node
        // create a doubly linked list out of the given tokens
        // in the doubly linked list, loop until we find these symbols: "+-*/"
        // if we find these symbols, then two positions previous to the symbol is "a"
        // and 1 position prev to the symbol is "b". We do the given symbol's operation with a and b in that order, and find the result
        // and store the result in the current node's value. 
        // now that we used prev->prev and prev, we don't need it anymore, so we update our curren't previous to prev->prev->prev, and 
        // prev->prev->prev 's next to our current node, essentially eliminating the middle numbers (a and b). 
        DoublyLinkedNode* head = new DoublyLinkedNode(tokens[0], nullptr, nullptr);
        DoublyLinkedNode* curr = head;
        
        // make a linked list out of the tokens. 
        for (int i = 1; i < tokens.size(); i++) {
            curr->next = new DoublyLinkedNode(tokens[i], curr, nullptr);
            curr = curr->next;
        }

        int output = 0;
        curr = head; // !!!!!!! otherwise use head, or different pointer. Forgot this !!!!
        while (curr != nullptr) {

            if (curr->val == "+" || curr->val == "-" || curr->val == "*" || curr->val == "/") {
                int a = stoi(curr->prev->prev->val);
                int b = stoi(curr->prev->val);
                int result = 0;
                if (curr->val == "+") {
                    result = a + b;
                } else if (curr->val == "-") {
                    result = a - b;
                } else if (curr->val == "*") {
                    result = a * b;
                } else {
                    result = a / b;
                }

                curr->val = to_string(result);
                curr->prev = curr->prev->prev->prev;
                if (curr->prev != nullptr) {
                    curr->prev->next = curr;
                }
            }

            output = stoi(curr->val);
            curr = curr->next;
        }

        return output;
    }
    // time: O(n)
    // space: O(n)
};
