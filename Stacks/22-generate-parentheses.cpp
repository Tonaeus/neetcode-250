#include <bits/stdc++.h>
using namespace std;

// Technique: Backtracking

// Time Complexity: O(n * Cat(n)) or O(4^n / √(n))
// Space Complexity: O(n * Cat(n)) or O(4^n / √(n))

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        dfs(n, n, ans, path);
        return ans;
    }

private: 
    void dfs(int open, int close, vector<string>& ans, string& path) {
        if (open == 0 and close == 0) {
            ans.push_back(path);
            return;
        }

        if (open > 0) {
            path.push_back('(');
            dfs(open - 1, close, ans, path);
            path.pop_back();
        }

        if (open < close) {
            path.push_back(')');
            dfs(open, close - 1, ans, path);
            path.pop_back();
        }

        return;
    }
};
