class Solution {
public:
    // idea: recursion (dfs)
    // pop back -> if operator, traverse right subtree, traverse left subtree ....
    // if operand -> go left to right, and do the correct operation with left and right in that order. 
    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back(); // in c++ this won't return the popped value, we use back() for this. 

        if (token != "+" && token != "-" && token != "*" && token != "/") {
            return stoi(token);
        }

        int right = dfs(tokens);
        int left = dfs(tokens); // this will give the left and right values for the corresponding
        // operator in the current stack. 

        if (token == "+") {
            return left + right;
        } else if (token == "-") {
            return left - right;
        } else if (token == "*") {
            return left * right;
        } else if (token == "/") {
            return left / right;
        }

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }

    // time: O(n)
    // space: O(n)
};
