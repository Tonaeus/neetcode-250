#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m - 1, n - 1, dp);
    }

private:
    int dfs(int i, int j, vector<vector<int>>& dp) {
        if (i < 0 or j < 0) {
            return 0;
        }

        if (i == 0 and j == 0) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = dfs(i - 1, j, dp) + dfs(i, j - 1, dp);
    }
};
