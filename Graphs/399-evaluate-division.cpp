#include <bits/stdc++.h>
using namespace std;

// Concept: Fraction
// Algorithm: Breadth-First Search

// Time Complexity: O(q * (v + e))
// Space Complexity: O(v + e + q)

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;

        for (int i = 0; i < equations.size(); i++) {
            string n = equations[i][0];
            string d = equations[i][1];
            g[n].push_back({d, values[i]});
            g[d].push_back({n, 1 / values[i]});
        }

        vector<double> ans;
        for (const auto& q : queries) {
            string src = q[0];
            string dest = q[1];
            ans.push_back(bfs(g, src, dest));
        }

        return ans;
    }

private:
    double bfs(unordered_map<string, vector<pair<string, double>>>& g, string& src, string& dest) {
        if (!g.contains(src) or !g.contains(dest)) {
            return -1.0;
        }

        queue<pair<string, double>> q;
        unordered_set<string> visited;  
        q.push({src, 1.0});
        visited.insert(src);
        
        while (!q.empty()) {
            auto [u, weight] = q.front();
            q.pop();

            if (u == dest) {
                return weight;
            }

            for (auto& [v, vWeight] : g[u]) {
                if (!visited.contains(v)) {
                    q.push({v, weight * vWeight});
                    visited.insert(v);
                }
            }
        }

        return -1.0;
    }
};
