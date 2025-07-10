#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        dfs(nums, 0, 0, ans);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int i, int sum, int& ans) {
        if (i == nums.size()) {
            ans += sum;
            return;
        }
        
        dfs(nums, i + 1, sum, ans);
        dfs(nums, i + 1, sum ^ nums[i], ans);

        return;
    }
};
