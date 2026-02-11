#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(dfs(nums, 0, n - 2, dp1), dfs(nums, 1, n - 1, dp2));
    }

private:
    int dfs(vector<int>& nums, int i, int j, vector<int>& dp) {
        if (j < i) {
            return 0;
        }

        if (j == i) {
            return nums[i];
        }

        if (dp[j] != -1) {
            return dp[j];
        }

        return dp[j] = max(dfs(nums, i, j - 1, dp), nums[j] + dfs(nums, i, j - 2, dp));
    }
};
