class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // idea: stack
        // loop through each token in tokens, if the token is a operand, add it to our stack 
        // this stack tracks all the numbers
        // once we hit an operand in the loop, pop the top 2 numbers from the stack, and do the operation
        // in correct order. 
        stack<int> st;
        for (string& token: tokens) {
            if (token == "+") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            } else if (token == "-") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            } else if (token == "*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            } else if (token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
    // time: O(n)
    // space: O(n)
};
