#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(min(n, k))

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (r - l > k) {
                window.erase(nums[l]);
                l++;
            }
            if (window.contains(nums[r])) {
                return true;
            }
            window.insert(nums[r]);
        }

        return false;
    }
};
