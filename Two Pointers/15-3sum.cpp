#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    l++;
                }
                else if (sum > 0) {
                    r--;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r and nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
