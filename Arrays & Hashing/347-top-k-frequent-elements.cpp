#include <bits/stdc++.h>
using namespace std;

// Algorithm: Bucket Sort

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(n + 1);

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [key, val] : freq) {
            buckets[val].push_back(key);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                if (ans.size() == k) {
                    return ans;
                }

                ans.push_back(num);
            }
        }

        return ans;
    }
};
