#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n * n)
// Space Complexity: (2^n * n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;
        dfs(nums, 0, ans, subset);

        return ans;
    }

private: 
    void dfs(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& subset) {
        ans.push_back(subset);

        for (int j = i; j < nums.size(); j++) {
            if (j > i and nums[j] == nums[j - 1]) {
                continue;
            }

            subset.push_back(nums[j]);
            dfs(nums, j + 1, ans, subset);
            subset.pop_back();
        }

        return;
    }
};
