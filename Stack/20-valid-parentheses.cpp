#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (!stack.empty() and map[c] == stack.top()) {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
