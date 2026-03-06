#include <bits/stdc++.h>
using namespace std;

// Algorithm: Kadane

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
};
