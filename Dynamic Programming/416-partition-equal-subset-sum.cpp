#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return dfs(nums, n - 1, target, dp);
    }

private:
    bool dfs(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (i < 0) {
            return target == 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool include = false;
        if (target - nums[i] >= 0) {
            include = dfs(nums, i - 1, target - nums[i], dp);
        }

        bool exclude = dfs(nums, i - 1, target, dp);

        return dp[i][target] = include or exclude;
    }
};
