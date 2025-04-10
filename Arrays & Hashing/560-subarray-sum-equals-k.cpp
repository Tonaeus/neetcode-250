#include <bits/stdc++.h>
using namespace std;

// Algorithm: Prefix Sum

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map = { {0, 1} };
        int sum = 0;
        int ans = 0;

        for (int num : nums) {
            sum += num;
            if (map.contains(sum - k)) {
                ans += map[sum - k];
            }
            map[sum]++;
        }

        return ans;
    }
};
