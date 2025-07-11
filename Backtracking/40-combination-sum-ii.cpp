#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n * n)

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> comb;
        dfs(candidates, 0, target, ans, comb);

        return ans;
    }

private:
    void dfs(vector<int>& candidates, int i, int target, vector<vector<int>>& ans, vector<int>& comb) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i and candidates[j] == candidates[j - 1]) {
                continue;
            }

            if (target - candidates[j] >= 0) {
                comb.push_back(candidates[j]);
                dfs(candidates, j + 1, target - candidates[j], ans, comb);
                comb.pop_back();
            }
        }

        return;
    }
};
