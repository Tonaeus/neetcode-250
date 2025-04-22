#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> windowFreq(26);
        int maxFreq = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            windowFreq[s[r] - 'A']++;
            maxFreq = max(maxFreq, windowFreq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                windowFreq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
