#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

// Time Complexity: O(r * c)
// Space Complexity: O(r * c)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int time = 0;
        int fresh = 0;

        queue<pair<int, int>> q;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 ) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (fresh > 0 and !q.empty()) {
            int sz = q.size();
            time++;

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (const auto& [dr, dc] : directions) {
                    int ni = i + dr;
                    int nj = j + dc;
                    if (ni >= 0 and ni < r and nj >= 0 and nj < c and grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
