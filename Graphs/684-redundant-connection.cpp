#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(v + e)
// Space Complexity: O(v)

class DisjointSet {
public:
    DisjointSet(int n) : parent(n), rank(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findSet(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = findSet(parent[v]);
    }

    bool unionSet(int u, int v) {
        int up = findSet(u);
        int vp = findSet(v);

        if (up == vp) {
            return false;
        }

        if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } 
        else if (rank[up] < rank[vp]) {
            parent[up] = vp;
        } 
        else {
            parent[vp] = up;
            rank[up]++;
        }

        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet disjointSet(edges.size() + 1);

        for (const auto& e : edges) {
            if (!disjointSet.unionSet(e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};
