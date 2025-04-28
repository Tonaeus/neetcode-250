#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Stack 

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stack;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            while (!stack.empty() and temperatures[stack.top()] < temperatures[i]) {
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return ans;
    }
};
