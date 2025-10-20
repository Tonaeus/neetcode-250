#include <bits/stdc++.h>
using namespace std;

// Algorithm: Bellman-Ford

// Time Complexity: O(v * e)
// Space Complexity: O(v)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            bool updated = false;
            for (const auto& t : times) {
                int u = t[0] - 1;
                int v = t[1] - 1;
                int wt = t[2];

                if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
                    if (i == n - 1) {
                        return -1;
                    }
                    updated = true;
                    dist[v] = dist[u] + wt;
                }
            }
            if (!updated) {
                break;
            }
        }

        int maxDist = *max_element(dist.begin(), dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};