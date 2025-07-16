#include <bits/stdc++.h>
using namespace std;

// Technique: Bitmask Dynamic Programming

// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n)

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int length = perimeter / 4;
        
        if (length * 4 != perimeter) {
            return false;
        }

        if (*max_element(matchsticks.begin(), matchsticks.end()) > length) {
            return false;
        }

        int n = matchsticks.size();
        
        vector<int> dp(1 << n, -1);

        return dfs(matchsticks, 4, 0, length, (1 << n) - 1, dp);
    }

private: 
    bool dfs(vector<int>& matchsticks, int k, int sum, int target, int mask, vector<int>& dp) {
        if (k == 1) {
            return true;
        }
 
        if (dp[mask] != -1) {
            return dp[mask];
        }

        if (sum == target) {
            return dfs(matchsticks, k - 1, 0, target, mask, dp);
        }

        bool res = false;
        for (int i = 0; i < matchsticks.size(); i++) {
            if (mask & (1 << i) and sum + matchsticks[i] <= target) {
                res |= dfs(matchsticks, k, sum + matchsticks[i], target, mask ^ (1 << i), dp);
            }
        }

        return dp[mask] = res;
    }
};
