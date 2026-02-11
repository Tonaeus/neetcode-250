#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(nums, n - 1, dp);
    }

private:
    int dfs(vector<int>& nums, int i, vector<int>& dp) {
        if (i < 0) {
            return 0;
        }

        if (i == 0) {
            return nums[0];
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(dfs(nums, i - 1, dp), nums[i] + dfs(nums, i - 2, dp));
    }
};
