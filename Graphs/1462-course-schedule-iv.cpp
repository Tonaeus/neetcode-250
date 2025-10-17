#include <bits/stdc++.h>
using namespace std;

// Algorithm: Topological Sort (Kahn)

// Time Complexity: O(v * (v + e) + q)
// Space Complexity: O(v^2 + e + q)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
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

        vector<unordered_set<int>> ancestors(numCourses);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : g[node]) {
                ancestors[nbr].insert(node);
                ancestors[nbr].insert(ancestors[node].begin(), ancestors[node].end());
                
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        vector<bool> ans;

        for (auto& q : queries) {
            ans.push_back(ancestors[q[0]].contains(q[1]));
        }

        return ans;
    }
};
