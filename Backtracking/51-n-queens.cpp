#include <bits/stdc++.h>
using namespace std;

// Technique: Bitmasking

// Time Complexity: O(n!)
// Space Complexity: O(n^2)

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        dfs(n, 0, 0, 0, 0, ans, board);
        return ans;
    }

private:
    void dfs(int n, int r, int col, int posDiag, int negDiag, vector<vector<string>>& ans, vector<string>& board) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int cBit = 1 << c;
            int pBit = 1 << (r + c);
            int nBit = 1 << (r - c + (n - 1)); 

            if (cBit & col or pBit & posDiag or nBit & negDiag) {
                continue;
            }

            board[r][c] = 'Q';
            dfs(n, r + 1, cBit | col, pBit | posDiag, nBit | negDiag, ans, board);
            board[r][c] = '.';
        }

        return;
    };
};
