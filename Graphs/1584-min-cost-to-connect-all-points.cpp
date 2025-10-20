#include <bits/stdc++.h>
using namespace std;

// Algorithm: Minimum Spanning Tree (Prim)

// Time Complexity: O(n^2 * log(n))
// Space Complexity: O(n^2)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<array<int, 2>>> g;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                g[i].push_back({dist, j});
                g[j].push_back({dist, i});
            }
        }

        int ans = 0;
        vector<bool> visited(n);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> minHeap;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            auto [uDist, u] = minHeap.top();
            minHeap.pop();

            if (visited[u]) {
                continue;
            }

            ans += uDist;
            visited[u] = true;

            for (auto& [vDist, v] : g[u]) {
                if (!visited[v]) {
                    minHeap.push({vDist, v}); 
                }
            }
        }

        return ans;
    }
};
