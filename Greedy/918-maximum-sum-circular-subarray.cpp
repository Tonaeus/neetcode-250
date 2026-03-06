#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMin = nums[0];
        int globalMax = nums[0];
        int localMin = 0;
        int localMax = 0;

        int totalSum = 0;

        for (int num : nums) {
            localMin = min(num, localMin + num);
            localMax = max(num, localMax + num);
            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
            
            totalSum += num;
        }

        return totalSum == globalMin ? globalMax : max(globalMax, totalSum - globalMin);
    }
};
