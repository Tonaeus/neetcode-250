#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(s1, s2, s3, m, n, dp);
    }

private:
    bool dfs(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 and j == 0) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool choice1 = false;
        if (i > 0 and s1[i - 1] == s3[i + j - 1]) {
            choice1 = dfs(s1, s2, s3, i - 1, j, dp); 
        }

        bool choice2 = false;
        if (j > 0 and s2[j - 1] == s3[i + j - 1]) {
            choice2 = dfs(s1, s2, s3, i, j - 1, dp); 
        }

        return dp[i][j] = choice1 or choice2;
    }
};
