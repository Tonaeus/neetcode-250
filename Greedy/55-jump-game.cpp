#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i <= farthest and i < n; i++) {
            farthest = max(farthest, i + nums[i]);
        }

        return farthest >= n - 1;
    }
};
