#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m + 2^n * n)
// Space Complexity: O(m + 2^n)

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<string> words;
        dfs(s, 0, set, ans, words);
        return ans;
    }

private:
    void dfs(string& s, int i, unordered_set<string>& wordDict, vector<string>& ans, vector<string>& words) {
        if (i == s.length()) {
            ans.push_back(join(words, " "));
            return;
        }

        for (int j = i; j < s.length(); j++) {
            string w = s.substr(i, j - i + 1);
            if (wordDict.contains(w)) {
                words.push_back(w);
                dfs(s, j + 1, wordDict, ans, words);
                words.pop_back();
            }
        }

        return;
    }

    string join(vector<string>& words, string delim) {
        if (words.empty()) {
            return "";
        }

        string res = words[0];
        for (int i = 1; i < words.size(); i++) {
            res += delim + words[i];
        }

        return res;
    }
};
