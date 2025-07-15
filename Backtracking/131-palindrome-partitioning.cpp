#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n * n)

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        dfs(s, 0, ans, parts);
        return ans;
    }

private:
    void dfs(string& s, int i, vector<vector<string>>& ans, vector<string>& parts) {
        if (i == s.length()) {
            ans.push_back(parts);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (palindrome(s, i, j)) {
                parts.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, ans, parts);
                parts.pop_back();
            }
        }

        return;
    }

    bool palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
