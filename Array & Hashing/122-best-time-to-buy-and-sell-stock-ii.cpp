#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }

        return ans;
    }
};
