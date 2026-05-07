#include <bits/stdc++.h>
using namespace std;

// Algorithm: Minimax

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return minimax(piles, 0, n - 1, dp) > 0;
    }

private:
    int minimax(vector<int>& piles, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != INT_MIN) {
            return dp[l][r];
        }

        int player = (r - l) % 2 == 0;
        int score = 0;
        
        if (player == 0) {
            int choice1 = piles[l] + minimax(piles, l + 1, r, dp);
            int choice2 = piles[r] + minimax(piles, l, r - 1, dp);
            score = max(choice1, choice2);
        }
        else {
            int choice1 = -piles[l] + minimax(piles, l + 1, r, dp);
            int choice2 = -piles[r] + minimax(piles, l, r - 1, dp);
            score = min(choice1, choice2);
        }

        return dp[l][r] = score;
    }
};
