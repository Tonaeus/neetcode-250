#include <bits/stdc++.h>
using namespace std;

// Technique: Bitmasking

// Time Complexity: O(n!)
// Space Complexity: O(n)

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        dfs(n, 0, 0, 0, 0, ans);
        return ans;
    }

private:
    void dfs(int n, int r, int col, int posDiag, int negDiag, int& ans) {
        if (r == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            int cBit = 1 << c;
            int pBit = 1 << (r + c);
            int nBit = 1 << (r - c + (n - 1));

            if (cBit & col or pBit & posDiag or nBit & negDiag) {
                continue;
            }

            dfs(n, r + 1, cBit | col, pBit | posDiag, nBit | negDiag, ans);
        }

        return;
    }
};
