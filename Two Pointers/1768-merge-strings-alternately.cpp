#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string ans;
        
        for (int i = 0; i < m or i < n; i++) {
            if (i < m) {
                ans.push_back(word1[i]);
            }
            if (i < n) {
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};
