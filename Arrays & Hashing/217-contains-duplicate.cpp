#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }

        return nums.size() != set.size();
    }
};
