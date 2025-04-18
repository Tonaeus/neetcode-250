#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> map;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (map.contains(s[r])) {
                l = max(l, map[s[r]] + 1);
            }
            map[s[r]] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
