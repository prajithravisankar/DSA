class Solution {
public:
    bool isValid(string s) {
        // create a stack to track the opening parentheses. 
        // create a map of closing parentheses => opening parentheses. 
        // loop through the given string, if the char not in map, add it to the stack cause it is opening
        // parentheses. 
        // if the char in map, check if the stack is not empty, and 
        // the map[ch] == stack's top (opening parentheses). if so pop the stack. 
        // if either of these cases are not true, return false. 
        // finally check if the stack is empty, if so return true, else return false. 
        stack<char> opening_parentheses_stack;
        unordered_map<char, char> closing_parentheses_to_opening_parentheses = {
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}
        };
        for (char c: s) {
            if (closing_parentheses_to_opening_parentheses.count(c)) {
                if (!opening_parentheses_stack.empty() && closing_parentheses_to_opening_parentheses[c] == opening_parentheses_stack.top()) {
                    opening_parentheses_stack.pop();
                } else {
                    return false;
                }
            } else {
                opening_parentheses_stack.push(c);
            }
        }

        return opening_parentheses_stack.empty();
    }
    // time: O(n)
    // space: O(n)
};
