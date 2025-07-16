#include <bits/stdc++.h>
using namespace std;

// Technique: Dynamic Programming + Bitmasking + Pruning

// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n)

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int partSum = totalSum / k; 
        if (partSum * k != totalSum) {
            return false;
        }

        sort(nums.rbegin(), nums.rend());
        if (nums.front() > partSum) {
            return false;
        }

        int n = nums.size();
        vector<int> dp(1 << n, -1);
        return dfs(nums, k, 0, partSum, (1 << n) - 1, dp);
    }

private: 
    bool dfs(vector<int>& nums, int k, int sum, int target, int mask, vector<int>& dp) {
        if (k == 1) {
            return true;
        }

        if (dp[mask] != -1) {
            return dp[mask];
        }

        if (sum == target) {
            return dfs(nums, k - 1, 0, target, mask, dp);
        }

        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) == 0 or sum + nums[i] > target) {
                continue; 
            }

            if (dfs(nums, k, sum + nums[i], target, mask ^ (1 << i), dp)) {
                return dp[mask] = true;
            }

            if (sum == 0) {
                return dp[mask] = false;
            }
        }

        return dp[mask] = false;
    }
};
