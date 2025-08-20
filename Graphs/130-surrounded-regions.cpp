#include <bits/stdc++.h>
using namespace std;

// Algorithm: Flood Fill (Depth-First Search)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            dfs(board, m, n, i, 0);
            dfs(board, m, n, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(board, m, n, 0, i);
            dfs(board, m, n, m - 1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }

private: 
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j) {
        if (i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'T';

        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (const auto& [dr, dc] : directions) {
            dfs(board, m, n, i + dr, j + dc);
        }

        return;
    }
};
