#include <bits/stdc++.h>
using namespace std;

// Algorithm: Dijksta

// Time Complexity: O(e·log(v))
// Space Complexity: O(v)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        efforts[0][0] = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap;
        minHeap.push({0, 0, 0}); // {effort, i, j}

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!minHeap.empty()) {
            auto [effort, i, j] = minHeap.top();
            minHeap.pop();

            for (auto [dr, dc] : directions) {
                int ni = i + dr;
                int nj = j + dc;

                if (ni < 0 or ni >= rows or nj < 0 or nj >= cols) {
                    continue;
                }

                int newEffort = abs(heights[i][j] - heights[ni][nj]);
                int pathEffort = max(effort, newEffort); 

                if (pathEffort < efforts[ni][nj]) {
                    efforts[ni][nj] = pathEffort;
                    minHeap.push({pathEffort, ni, nj});
                }
            }
        }

        return efforts[rows - 1][cols - 1];
    }
};
