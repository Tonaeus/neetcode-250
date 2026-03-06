#include <bits/stdc++.h>
using namespace std;

// Algorithm: Kadane

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;

        for (int num : nums) {
            sum = max(num, sum + num);
            ans = max(ans, sum);
        }

        return ans;
    }
};
