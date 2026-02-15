#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n * l) -> m = length of s, n = size of wordDict, l = average word length
// Space Complexity: O(m)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.length();
        vector<int> dp(m + 1, -1);
        return dfs(s, m, wordDict, dp);
    }

private:
    bool dfs(string& s, int i, vector<string>& wordDict, vector<int>& dp) {
        if (i == 0) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        for (string& w : wordDict) {
            int l = w.length();
            if (i - l >= 0 and s.substr(i - l, l) == w) {
                if (dfs(s, i - l, wordDict, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
};
