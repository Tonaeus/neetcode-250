#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9); 
        vector<unordered_set<char>> cols(9); 
        vector<unordered_set<char>> boxes(9); 
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }

                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].contains(board[r][c]) or 
                    cols[c].contains(board[r][c]) or 
                    boxes[boxIndex].contains(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                boxes[boxIndex].insert(board[r][c]);
            }
        }

        return true;
    }
};
