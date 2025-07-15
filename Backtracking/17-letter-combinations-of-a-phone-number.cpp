#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^n * n)
// Space Complexity: O(4^n * n)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        string comb;
        dfs(digits, map, 0, ans, comb);

        return ans;
    }

private:
    void dfs(string& digits, unordered_map<char, string>& map, int i, vector<string>& ans, string& comb) {
        if (i == digits.length()) {
            ans.push_back(comb);
            return;
        }

        for (char c : map[digits[i]]) {
            comb.push_back(c);
            dfs(digits, map, i + 1, ans, comb);
            comb.pop_back();
        }

        return;
    }
};
