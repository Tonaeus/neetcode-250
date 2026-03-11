#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int currFarthest = 0;
        int nextFarthest = 0;
        int ans = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            nextFarthest = max(nextFarthest, i + nums[i]);
            
            if (i == currFarthest) {
                currFarthest = nextFarthest;
                ans++;
            } 
        }

        return ans;
    }
};
