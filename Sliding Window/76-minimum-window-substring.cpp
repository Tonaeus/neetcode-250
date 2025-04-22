#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m)
// Space Complexity: O(m)

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<int> windowFreq(128);
        vector<int> tFreq(128);

        for (char c : t) {
            tFreq[c]++;
        }

        int have = 0;
        int need = unordered_set<char>(t.begin(), t.end()).size();

        int start = 0;
        int len = INT_MAX;

        int l = 0;
        for (int r = 0; r < m; r++) {
            windowFreq[s[r]]++;
            
            if (tFreq[s[r]] > 0 and windowFreq[s[r]] == tFreq[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < len) {
                    start = l;
                    len = r - l + 1;
                }

                windowFreq[s[l]]--;
                if (tFreq[s[l]] > 0 and windowFreq[s[l]] < tFreq[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return len != INT_MAX ? s.substr(start, len) : "";
    }
};
