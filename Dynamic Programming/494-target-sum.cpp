#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * sum)
// Space Complexity: O(n * sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return dfs(nums, n - 1, target, sum, 0, dp);
    }

private:
    int dfs(vector<int>& nums, int i, int target, int offset, int sum, vector<vector<int>>& dp) {
        if (i == -1) {
            return sum == target;
        }

        if (dp[i][offset + sum] != -1) {
            return dp[i][offset + sum];
        } 

        int pos = dfs(nums, i - 1, target, offset, sum + nums[i], dp);
        int neg = dfs(nums, i - 1, target, offset, sum - nums[i], dp);

        return dp[i][offset + sum] = pos + neg;
    }
};
