#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return dfs(cost, n, dp);
    }

private:
    int dfs(vector<int>& cost, int n, vector<int>& dp) {
        if (n == 0 or n == 1) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = min(cost[n - 1] + dfs(cost, n - 1, dp), cost[n - 2] + dfs(cost, n - 2, dp));
    }
};
