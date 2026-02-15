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
    bool dfs(vector<int>& nums, int j, int target, vector<vector<int>>& dp) {
        if (j < 0) {
            return target == 0;
        }

        if (dp[j][target] != -1) {
            return dp[j][target];
        }

        bool include = false;
        if (target - nums[j] >= 0) {
            include = dfs(nums, j - 1, target - nums[j], dp);
        }

        bool exclude = dfs(nums, j - 1, target, dp);

        return dp[j][target] = include or exclude;
    }
};
