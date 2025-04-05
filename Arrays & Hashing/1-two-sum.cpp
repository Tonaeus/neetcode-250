#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; 

        for (int i = 0; i < nums.size(); i++) {
            if (map.contains(nums[i])) {
                return {map[nums[i]], i};
            }
            else {
                map[target - nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
