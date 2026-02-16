#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;
            ans = (ans << 1) | bit;  
        }

        return ans;
    }
};
