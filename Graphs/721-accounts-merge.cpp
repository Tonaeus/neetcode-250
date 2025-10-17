#include <bits/stdc++.h>
using namespace std;

// Data Structure: Disjoint Set

// Time Complexity: O(a * e * log(e)) -> a = number of accounts, e = number of emails
// Space Complexity: O(a + e)

class DisjointSet {
public:
    DisjointSet(int n) : parent(n), rank(n, 1) {
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
            rank[up] += rank[vp];
        } 
        else {
            parent[up] = vp;
            rank[vp] += rank[up];
        }

        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet disjointSet(n);

        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (map.contains(accounts[i][j])) {
                    disjointSet.unionSet(map[accounts[i][j]], i);
                }
                else {
                    map[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> uniqueAccounts;
        for (const auto& [email, id] : map) {
            int account = disjointSet.findSet(id);
            uniqueAccounts[account].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [id, emails] : uniqueAccounts) {
            sort(emails.begin(), emails.end());
            
            vector<string> merged;
            merged.push_back(accounts[id][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());

            ans.push_back(merged);
        }

        return ans;
    }
};
