#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(piles, 0, n - 1, dp) > 0;
    }

private:
    int dfs(vector<int>& piles, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int turn = (r - l) % 2 == 0;

        int choice1 = (turn ? -piles[l] : piles[l]) + dfs(piles, l + 1, r, dp);
        int choice2 = (turn ? -piles[r] : piles[r]) + dfs(piles, l, r - 1, dp);

        return dp[l][r] = turn ? min(choice1, choice2) : max(choice1, choice2);
    }
};
