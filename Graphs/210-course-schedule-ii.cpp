#include <bits/stdc++.h>
using namespace std;

// Algorithm: Topological Sort (Kahn)

// Time Complexity: O(v + e)
// Space Complexity: O(v + e)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses);

        for (const auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int nbr : g[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return ans.size() != numCourses ? vector<int>() : ans;
    }
};
