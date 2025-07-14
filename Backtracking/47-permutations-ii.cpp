#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n! * n)
// Space Complexity: O(n! * n)

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> perm;
        vector<bool> choices(nums.size(), true);
        dfs(nums, ans, perm, choices);

        return ans;
    }

private: 
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& perm, vector<bool> choices) {
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i - 1] and choices[i - 1]) {
                continue;
            }

            if (choices[i]) {
                perm.push_back(nums[i]);
                choices[i] = false;
                dfs(nums, ans, perm, choices);
                perm.pop_back();
                choices[i] = true;
            }
        }

        return;
    }
};
