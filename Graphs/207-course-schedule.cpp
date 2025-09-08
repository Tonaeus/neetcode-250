#include <bits/stdc++.h>
using namespace std;

// Algorithm: Cycle Detection (Depth-First Search)

// Time Complexity: O(v + e)
// Space Complexity: O(v + e)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> g(numCourses);
        for (const auto& p : prerequisites) {
            g[p[0]].insert(p[1]);
        }

        vector<bool> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(g, visited, i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(vector<unordered_set<int>>& g, vector<bool>& visited, int v) {
        if (g[v].empty()) {
            return true;
        }

        if (visited[v]) {
            return false;
        }

        visited[v] = true;
        for (const int nbr : g[v]) {
            if (!dfs(g, visited, nbr)) {
                return false;
            }
        }
        visited[v] = false;

        g[v].clear();
        return true;
    }
};
