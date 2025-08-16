#include <bits/stdc++.h>
using namespace std;

// Algorithm: Flood Fill (Depth-First Search)

// Time Complexity: O(r * c)
// Space Complexity: O(r * c)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, r, c, i, j);
                }
            }
        }

        return -1;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int i, int j) {
        if (i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == -1) {
            return 0;
        }

        grid[i][j] = -1;

        int res = 0;

        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (const auto& [dr, dc] : directions) {
            res += dfs(grid, r, c, i + dr, j + dc);
        }

        return res;
    }
};
