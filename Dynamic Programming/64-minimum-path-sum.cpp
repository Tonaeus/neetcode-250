#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        return dfs(grid, rows, cols, 0, 0, dp);
    }

private:
    int dfs(vector<vector<int>>& grid, int rows, int cols, int i, int j, vector<vector<int>>& dp) {
        if (i == rows - 1 and j == cols - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = INT_MAX;
        if (i + 1 < rows) {
            res = min(res, dfs(grid, rows, cols, i + 1, j, dp));
        }

        if (j + 1 < cols) {
            res = min(res, dfs(grid, rows, cols, i, j + 1, dp));
        }

        return dp[i][j] = grid[i][j] + res;
    }
};
