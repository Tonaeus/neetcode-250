#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> s1Freq(26);
        vector<int> s2Freq(26);

        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < n; r++) {
            if (r - l + 1 > m) {
                s2Freq[s2[l] - 'a']--;
                l++;
            }

            s2Freq[s2[r] - 'a']++;
            
            if (s1Freq == s2Freq) {
                return true;
            }
        }

        return false;
    }
};
