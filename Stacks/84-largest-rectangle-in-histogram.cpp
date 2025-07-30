#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Stack

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        stack<pair<int, int>> ims;
        
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!ims.empty() and ims.top().second > heights[i]) {
                auto [index, height] = ims.top();
                ans = max(ans, height * (i - index));
                start = index;
                ims.pop();
            }
            ims.push({start, heights[i]});
        }

        while (!ims.empty()) {
            auto [index, height] = ims.top();
            ans = max(ans, height * (n - index));
            ims.pop();
        }

        return ans;
    }
};    
