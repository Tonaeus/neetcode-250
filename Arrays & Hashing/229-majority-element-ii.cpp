#include <bits/stdc++.h>
using namespace std;

// Algorithm: Boyer-Moore Majority Vote

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;

            if (map.size() > 2) {
                for (auto& [key, val] : map) {
                    val--;
                }
                erase_if(map, [](auto& pair) {
                    auto& [key, val] = pair;
                    return val == 0;
                });
            }
        }
        
        vector<int> ans;
        for (auto& [key, val] : map) {
            int cnt = count(nums.begin(), nums.end(), key);
            if (cnt > nums.size() / 3) {
                ans.push_back(key);
            }
        }

        return ans;
    }
};
