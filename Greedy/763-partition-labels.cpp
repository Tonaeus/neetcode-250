#include <bits/stdc++.h>
using namespace std;

// Technique: Two Pointers

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        
        vector<int> freq(26);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, freq[s[i] - 'a']);

            if (i == r) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }

        return ans;
    }
};
