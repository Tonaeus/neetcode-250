#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return dfs(coins, n - 1, amount, dp);
    }

private:
    int dfs(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (i < 0 or amount < 0) {
            return 0;
        }

        if (amount == 0) {
            return 1;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int include = dfs(coins, i, amount - coins[i], dp);
        int exclude = dfs(coins, i - 1, amount, dp);

        return dp[i][amount] = include + exclude;
    }
};
