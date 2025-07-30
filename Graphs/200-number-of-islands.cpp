#include <bits/stdc++.h>
using namespace std;

// Algorithm: Flood Fill

// Time Complexity: O(r * c)
// Space Complexity: O(r * c)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int ans = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, r, c, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c, int i, int j) {
        if (i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (const auto& [dr, dc] : directions) {
            dfs(grid, r, c, i + dr, j + dc);
        }

        return;
    }
};
