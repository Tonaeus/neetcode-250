#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O([n! / ((n - k)! * k!)] * k)
// Space Complexity: O([n! / ((n - k)! * k!)] * k)

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(n, 1, k, ans, comb);
        return ans;
    }

private: 
    void dfs(int n, int i, int k, vector<vector<int>>& ans, vector<int> comb) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for (int j = i; j <= n; j++) {
            comb.push_back(j);
            dfs(n, j + 1, k, ans, comb);
            comb.pop_back();
        }

        return;
    }
};
