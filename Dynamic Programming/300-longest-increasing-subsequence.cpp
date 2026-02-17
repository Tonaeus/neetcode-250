#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(nums, i, dp)); 
        }

        return ans;
    }

private: 
    int dfs(vector<int>& nums, int i, vector<int>& dp) {
        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], 1 + dfs(nums, j, dp));
            }
        }

        return dp[i];
    }
};
