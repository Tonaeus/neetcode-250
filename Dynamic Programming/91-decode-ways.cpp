#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return dfs(s, n - 1, dp);
    }

private:
    int dfs(string& s, int i, vector<int>& dp) {
        if (i < 0) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ways = 0;

        if (s[i] != '0') {
            ways += dfs(s, i - 1, dp);
        }

        if (i > 0 and (s[i - 1] == '1' or (s[i - 1] == '2' and s[i] <= '6'))) {
            ways += dfs(s, i - 2, dp);
        }

        return dp[i] = ways;
    }
};
