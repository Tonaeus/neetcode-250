#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(log(n))

class Solution {
vector<vector<int>> ans;
vector<int> addends;

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) {
            return {};
        }

        sort(nums.begin(), nums.end());
        kSum(nums, target, 0, n - 1, 4);
        
        return ans;
    }

private: 
    void kSum(vector<int>& nums, long target, int l, int r, int k) {
        if (k == 2) {
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < target) {
                    l++;
                }
                else if (sum > target) {
                    r--;
                }
                else {
                    addends.push_back(nums[l]);
                    addends.push_back(nums[r]);
                    ans.push_back(addends);
                    addends.pop_back();
                    addends.pop_back();
                    l++;
                    r--;
                    while (l < r and nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }

            return;
        }

        int n = nums.size();

        for (int i = l; i < n; i++) {
            if (i > l and nums[i] == nums[i - 1]) {
                continue;
            }
            addends.push_back(nums[i]);
            kSum(nums, target - nums[i], i + 1, n - 1, k - 1);
            addends.pop_back();
        }

        return;
    }
};
