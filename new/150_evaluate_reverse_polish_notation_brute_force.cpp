class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // idea: brute force
        // while loop until we have one token left. 
        // for loop each token in the tokens until we find one of these signs: +, -, *, /
        // if we find the sign at ith index, a = value at i - 2, b = value at i - 1
        // find relevant result of the relevant operation: a + b, a - b, a * b, a / b
        // insert the result in the correct position {..., i - 2, <NEW VALUE>, i + 1, ....}
        // return the new tokens
        while (tokens.size() > 1) {
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    int a = stoi(tokens[i - 2]);
                    int b = stoi(tokens[i - 1]);
                    int result = 0;
                    if (tokens[i] == "+") {
                        result = a + b;
                    } else if (tokens[i] == "-") {
                        result = a - b;
                    } else if (tokens[i] == "*") {
                        result = a * b;
                    } else {
                        result = a / b;
                    }
                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
    // time: O(n^2)
    // space: O(n)
};
