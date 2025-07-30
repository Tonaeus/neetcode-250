#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token.empty()) {
                continue;
            }
            else if (token != "." and token != "..") {
                tokens.push_back(token);
            }
            else if (token == ".." and !tokens.empty()) {
                tokens.pop_back();
            }
        }

        string ans;

        for (string& str : tokens) {
            ans.push_back('/');
            ans.append(str);
        }

        return ans.empty() ? "/" : ans;
    }
};
