#include <bits/stdc++.h>
using namespace std;

// Algorithm: Counting Sort

// Time Complexity: O(n + k)
// Space Complexity: O(n + k)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int minVal = min(*min_element(nums.begin(), nums.end()), 0);
        int maxVal = *max_element(nums.begin(), nums.end());
        int k = maxVal - minVal;

        vector<int> count(k + 1);
        vector<int> output(n);

        for (int i = 0; i < n; i++) {
            int j = nums[i] - minVal;
            count[j]++;
        }

        for (int i = 1; i < k + 1; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int j = nums[i] - minVal;
            output[count[j] - 1] = nums[i];
            count[j]--;
        }

        return output;
    }
};
