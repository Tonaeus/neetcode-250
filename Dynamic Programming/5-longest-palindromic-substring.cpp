#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int pos = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dfs(s, i, j, dp) and j - i + 1 > maxLen) {
                    pos = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(pos, maxLen);
    }

private:
    bool dfs(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == s[j]) {
            return dp[i][j] = dfs(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = false;
    }
};
