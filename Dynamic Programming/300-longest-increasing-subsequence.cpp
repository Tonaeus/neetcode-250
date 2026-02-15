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
    int dfs(vector<int>& nums, int j, vector<int>& dp) {
        if (dp[j] != -1) {
            return dp[j];
        }

        dp[j] = 1;

        for (int i = 0; i < j; i++) {
            if (nums[i] < nums[j]) {
                dp[j] = max(dp[j], 1 + dfs(nums, i, dp));
            }
        }

        return dp[j];
    }
};
