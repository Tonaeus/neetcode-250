#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        unordered_set<string> operations = {"+", "-", "*", "/"};

        for (string& token : tokens) {
            if (!operations.contains(token)) {
                stack.push(stoi(token));
                continue;
            }

            int operand2 = stack.top(); 
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            }
            else if (token == "-") {
                stack.push(operand1 - operand2);
            }
            else if (token == "*") {
                stack.push(operand1 * operand2);
            }
            else if (token == "/") {
                stack.push(operand1 / operand2);
            }
        }

        return stack.top();
    }
};
