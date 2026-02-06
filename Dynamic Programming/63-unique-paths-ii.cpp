#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(obstacleGrid, m - 1, n - 1, dp);
    }

private:
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 or j < 0 or obstacleGrid[i][j]) {
            return 0;
        }

        if (i == 0 and j == 0) {
            return !obstacleGrid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = dfs(obstacleGrid, i - 1, j, dp) + dfs(obstacleGrid, i, j - 1, dp);
    }
};
