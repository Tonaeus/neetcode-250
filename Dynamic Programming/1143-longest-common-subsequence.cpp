#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(text1, text2, m - 1, n - 1, dp);
    }

private:
    int dfs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i == -1 or j == -1) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + dfs(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(dfs(text1, text2, i, j - 1, dp), dfs(text1, text2, i - 1, j, dp)); 
    }
};
