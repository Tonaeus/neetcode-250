#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * s) -> n = size of nums, s = total sum of nums
// Space Complexity: O(n * s)

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return (sum - dfs(stones, n - 1, target, dp)) - dfs(stones, n - 1, target, dp);
    }

private:
    int dfs(vector<int>& stones, int i, int target, vector<vector<int>>& dp) {
        if (i == -1) {
            return 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int include = 0;
        if (target - stones[i] >= 0) {
            include = stones[i] + dfs(stones, i - 1, target - stones[i], dp);
        }

        int exclude = dfs(stones, i - 1, target, dp);

        return dp[i][target] = max(include, exclude);
    }
};
