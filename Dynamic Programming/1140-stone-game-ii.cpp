#include <bits/stdc++.h>
using namespace std;

// Algorithm: Minimax

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return minimax(piles, n, 0, 0, 1, dp);
    }

private:
    int minimax(vector<int>& piles, int n, int player, int i, int M, vector<vector<vector<int>>>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[player][i][M] != -1) {
            return dp[player][i][M];
        }

        int score = player == 0 ? INT_MIN : INT_MAX;

        if (player == 0) {
            int sum = 0;
            for (int X = 1; X <= 2 * M and i + X - 1 < n; X++) {
                sum += piles[i + X - 1];
                score = max(score, sum + minimax(piles, n, 1, i + X, max(M, X), dp));
            }
        }
        else {
            for (int X = 1; X <= 2 * M and i + X - 1 < n; X++) {
                score = min(score, minimax(piles, n, 0, i + X, max(M, X), dp));
            }
        }

        return dp[player][i][M] = score;
    }
};
