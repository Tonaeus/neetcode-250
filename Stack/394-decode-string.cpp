#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + N) -> n = length of input string, N = length of output string
// Space Complexity: O(n + N)

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> intStack;
        string curr = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                strStack.push(curr);
                intStack.push(k);
                curr = "";
                k = 0;
            }
            else if (c == ']') {
                string prev = strStack.top();
                for (int i = 0; i < intStack.top(); i++) {
                    prev += curr;
                }
                curr = prev;
                strStack.pop();
                intStack.pop();
            }
            else {
                curr += c;
            }
        }
        
        return curr;
    }
};
