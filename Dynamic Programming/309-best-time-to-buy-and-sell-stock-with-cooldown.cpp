#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(prices, 0, false, dp);
    }

private:
    int dfs(vector<int>& prices, int i, bool h, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][h] != -1) {
            return dp[i][h];
        }

        int buy = 0;
        if (h == false) {
            buy = -prices[i] + dfs(prices, i + 1, true, dp);
        }
        
        int sell = 0;
        if (h == true) {
            sell = prices[i] + dfs(prices, i + 2, false, dp);
        }
        
        int hold = dfs(prices, i + 1, h, dp);

        return dp[i][h] = max({buy, sell, hold});
    }
};
