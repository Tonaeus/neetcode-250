#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * 4^n) -> n = number of cells
// Space Complexity: O(n)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private: 
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if (board[r][c] != word[i]) {
            return false;
        }
        if (i == word.length() - 1) {
            return true;
        }

        char letter = board[r][c];
        board[r][c] = '#';

        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1]; 

            if (nr < 0 or nr >= board.size() or
                nc < 0 or nc >= board[0].size()) {
                continue;
            }

            if (dfs(board, nr, nc, word, i + 1)) {
                return true;
            }
        }

        board[r][c] = letter;

        return false;
    }
};
