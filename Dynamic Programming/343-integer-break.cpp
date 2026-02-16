#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp);
    }

private:
    int dfs(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = 0;

        for (int i = 1; i < n; i++) {
            if (n - i >= 0) {
                dp[n] = max({dp[n], i * (n - i), i * dfs(n - i, dp)});
            }
        }

        return dp[n];
    }
};
