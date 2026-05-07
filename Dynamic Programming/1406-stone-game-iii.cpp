#include <bits/stdc++.h>
using namespace std;

// Algorithm: Minimax

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MIN)); 
        int score = minimax(stoneValue, n, 0, 0, dp);
        return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie"; 
    }

private:
    int minimax(vector<int>& stoneValue, int n, int player, int i, vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[player][i] != INT_MIN) {
            return dp[player][i];;
        }

        int score = player == 0 ? INT_MIN : INT_MAX;

        if (player == 0) {
            int sum = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                sum += stoneValue[j];
                score = max(score, sum + minimax(stoneValue, n, 1, j + 1, dp));
            }
        }
        else {
            int sum = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                sum -= stoneValue[j];
                score = min(score, sum + minimax(stoneValue, n, 0, j + 1, dp));
            }
        }

        return dp[player][i] = score; 
    }
};
