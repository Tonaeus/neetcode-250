#include <bits/stdc++.h>
using namespace std;

// Algorithm: Brian Kernighan

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;

        while (n) {
            n &= n - 1;
            ans++;
        }

        return ans;
    }
};
