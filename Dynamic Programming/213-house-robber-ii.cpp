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
    int dfs(vector<int>& nums, int l, int r, vector<int>& dp) {
        if (r < l) {
            return 0;
        }

        if (r == l) {
            return nums[l];
        }

        if (dp[r] != -1) {
            return dp[r];
        }

        return dp[r] = max(dfs(nums, l, r - 1, dp), nums[r] + dfs(nums, l, r - 2, dp));
    }
};
