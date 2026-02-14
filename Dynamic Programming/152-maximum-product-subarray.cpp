#include <bits/stdc++.h>
using namespace std;

// Algorithm: Kadane

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
    
        int curMin = nums[0];
        int curMax = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (num < 0) {
                swap(curMin, curMax);
            }

            curMin = min(num, curMin * num);
            curMax = max(num, curMax * num);

            ans = max(ans, curMax);
        }

        return ans;
    }
};
