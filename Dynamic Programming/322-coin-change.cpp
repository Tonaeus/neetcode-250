#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return dfs(coins, amount, dp);
    }

private:
    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0) {
            return -1;
        }

        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -2) {
            return dp[amount];
        }

        dp[amount] = INT_MAX;

        for (int c : coins) {
            int res = dfs(coins, amount - c, dp);
            if (res >= 0) {
                dp[amount] = min(dp[amount], 1 + res);
            }
        }

        return dp[amount] = dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
