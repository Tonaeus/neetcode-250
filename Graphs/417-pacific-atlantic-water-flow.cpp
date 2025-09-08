#include <bits/stdc++.h>
using namespace std;

// Algorithm: Graph Traversal (Breadth-First Search)

// Time Complexity: O(r * c)
// Space Complexity: O(r * c)

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        vector<vector<bool>> pacific(r, vector<bool>(c));
        vector<vector<bool>> atlantic(r, vector<bool>(c));;
        
        queue<pair<int, int>> pacificQ;
        queue<pair<int, int>> atlanticQ;

        for (int i = 0; i < r; i++) {
            pacificQ.push({i, 0});
            atlanticQ.push({i, c - 1});
        }
        for (int i = 0; i < c; i++) {
            pacificQ.push({0, i});
            atlanticQ.push({r - 1, i});
        }

        bfs(heights, r, c, pacific, pacificQ);
        bfs(heights, r, c, atlantic, atlanticQ);

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (pacific[i][j] and atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

private:
    void bfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean, queue<pair<int, int>>& q) {
        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            ocean[i][j] = true;

            for (const auto& [dr, dc] : directions) {
                int ni = i + dr;
                int nj = j + dc;
                if (ni >= 0 and ni < r and nj >= 0 and nj < c and !ocean[ni][nj] and heights[ni][nj] >= heights[i][j]) {
                    q.push({ni, nj});
                }
            }
        }
        return;
    }
};
