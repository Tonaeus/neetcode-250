#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return dfs(nums, target, dp);
    }

private:
    int dfs(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) {
            return 1;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        dp[target] = 0;

        for (int num : nums) {
            if (target - num >= 0) {
                dp[target] += dfs(nums, target - num, dp);
            }
        }

        return dp[target];
    }
};
