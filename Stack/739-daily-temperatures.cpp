#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Stack 

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> dms;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            while (!dms.empty() and temperatures[dms.top()] < temperatures[i]) {
                ans[dms.top()] = i - dms.top();
                dms.pop();
            }
            dms.push(i);
        }

        return ans;
    }
};
