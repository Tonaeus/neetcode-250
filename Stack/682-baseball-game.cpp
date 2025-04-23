#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;

        for (string& op : operations) {
            if (op == "+") {
                stack.push_back(stack[stack.size() - 2] + stack.back());
            }
            else if (op == "D") {
                stack.push_back(stack.back() * 2);
            }
            else if (op == "C") {   
                stack.pop_back();
            }
            else {
                stack.push_back(stoi(op));
            }
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }
};
