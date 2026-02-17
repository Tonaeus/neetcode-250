#include <bits/stdc++.h>
using namespace std;

// Concept: Game Theory

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN)); 
        int res = minimax(stoneValue, n, 0, 0, dp);

        if (res > 0) {
            return "Alice";
        }
        if (res < 0) {
            return "Bob";
        }
        return "Tie";
    }

private:
    int minimax(vector<int>& stoneValue, int n, int i, int p, vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i][p] != INT_MIN) {
            return dp[i][p];
        }

        dp[i][p] = p == 0 ? INT_MIN : INT_MAX;

        int score = 0;
        for (int j = i; j < min(n, i + 3); j++) {
            if (p == 0) {
                score += stoneValue[j];
                dp[i][p] = max(dp[i][p], score + minimax(stoneValue, n, j + 1, !p, dp));
            }   
            else {
                score -= stoneValue[j];
                dp[i][p] = min(dp[i][p], score + minimax(stoneValue, n, j + 1, !p, dp));
            }
        }

        return dp[i][p]; 
    }
};
